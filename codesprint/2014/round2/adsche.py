
#-*- coding: utf-8 -*-


import sys
import httplib
import json
import time
import random
import cPickle

class AdScore:
	def __init__(self, ad_list, media_list):
		self.media_free_ad_count = { }
		self.media_paid_ad_count = { }
		self.media_ad_clicks = { }
		self.media_list = media_list
		self.ad_profit = 0
		self.cost = ad_list.cost

	def add_profit(self, profit):
		self.ad_profit += profit

	def add_ad_count(self, schedule):
		for media_no, ads in schedule.items():
			for ad_no, count in ads.items():
				if self.cost[ad_no] == 0:
					self.media_free_ad_count[media_no] = self.media_free_ad_count.get(media_no, 0) + count
				else:
					self.media_paid_ad_count[media_no] = self.media_paid_ad_count.get(media_no, 0) + count

	def get_fr(self, media_no):
		free_cnt = self.media_free_ad_count.get(media_no, 0)
		paid_cnt = self.media_paid_ad_count.get(media_no, 0)
		if free_cnt + paid_cnt == 0: return 0
		return 100.0 * paid_cnt / (free_cnt + paid_cnt)

	def get_fr_sum(self):
		fr_error = 0.0
		for media_no in self.media_list.get_media_ids():
			fr_error += abs(self.media_list.fill_ratio[media_no] - self.get_fr(media_no))
		return fr_error

	def get_score(self):
		return self.ad_profit - self.ad_profit * 0.01 * self.get_fr_sum()


class AdList:
	def __init__(self, data):
		self.turn_no = data.get('turnNo', None)
		self.time_seq = data.get('timeSeq', None)
		self.cost = { }
		self.impression = { }
		self.initial_impression = { }
		for ad in data['data']:
			no = ad['adNo']
			self.cost[no] = ad['adCost']
			self.impression[no] = ad['impressionCount']
			self.initial_impression[no] = ad['impressionCount']


	def get_free_ads(self):
		return filter(lambda x: self.cost[x] == 0, self.cost.keys())

	def get_paid_ads(self):
		return filter(lambda x: self.cost[x] != 0 , self.cost.keys())		

	def get_paid_ad(self, prob, impression, alpha=1.0):
		paid_ads = sorted(self.get_paid_ads(), key=lambda x: self.cost[x], reverse=True)
		accumulated_impression = 0
		total_impression = sum(map(lambda x: self.initial_impression[x], self.get_paid_ads()))
		idx = 0
		while idx < len(paid_ads):
			accumulated_impression += self.initial_impression[paid_ads[idx]]
			if total_impression - accumulated_impression < total_impression * prob * alpha:
				break
			idx += 1

		idx = min(idx, len(paid_ads)-1)

		while idx > 0 and self.cost[paid_ads[idx]] == self.cost[paid_ads[idx-1]]:
			idx -= 1

		#print 'prob=', prob, ' impression=', impression, ' ad_no=' , paid_ads[idx]
		ads = []
		for i in xrange(idx, len(paid_ads)):
			imp = min(self.impression[paid_ads[i]], impression)
			if imp == 0: continue
			ads.append((paid_ads[i], imp))
			impression -= imp
			if impression <= 0:
				return ads
		for i in xrange(idx, -1, -1):
			imp = min(self.impression[paid_ads[i]], impression)
			if imp == 0: continue
			ads.append((paid_ads[i], imp))
			impression -= imp
			if impression <= 0:
				return ads
		return ads

	def get_paid_ad2(self, cpr, impression, alpha=1.0):
		paid_ads = sorted(self.get_paid_ads(), key=lambda x: self.cost[x], reverse=True)
		max_clicks = 1200
		idx = 0
		# 200: 0.03030303030303
		# 100: 0.06060606060606
		# 10 : 0.3030303030303
		#  1 : 0.60606060606061

		# 0.0416 0.0578 0.063
		if cpr * alpha >= 0.0578:
			idx = 0 # cost 200
		elif cpr * alpha >= 0.053:
			idx = 4 # cost 100
		elif cpr * alpha >= 0.024:
			idx = 8 # cost 10
		else:
			idx = 12 # cost 1

		#print 'prob=', prob, ' impression=', impression, ' ad_no=' , paid_ads[idx]
		ads = []
		for i in xrange(idx, len(paid_ads)):
			imp = min(self.impression[paid_ads[i]], impression)
			if imp == 0: continue
			ads.append((paid_ads[i], imp))
			impression -= imp
			if impression <= 0:
				return ads
		for i in xrange(idx, -1, -1):
			imp = min(self.impression[paid_ads[i]], impression)
			if imp == 0: continue
			ads.append((paid_ads[i], imp))
			impression -= imp
			if impression <= 0:
				return ads
		#if impression: print 'not enought', impression, int(sum(media_list.max_impression.values()) * max_impression_scale)
		return ads

	def get_ads(self):
		return self.cost.keys()

class MediaList:
	def __init__(self, data):
		self.turn_no = data.get('turnNo', None)
		self.time_seq = data.get('timeSeq', None)
		self.fill_ratio = { }
		self.max_impression = { }
		for media in data['data']:
			no = media['mediaNo']
			self.fill_ratio[no] = media['fillRate']
			self.max_impression[no] = media['maxImpressionCountPerRequest']

	def get_media_ids(self):
		return self.fill_ratio.keys()

class Schedule:
	def __init__(self, ad_list, media_list):
		self.schedule = { }
		self.ad_list = ad_list
		self.media_list = media_list

	def add(self, media_no, ad_no, count):
		if media_no not in self.schedule:
			self.schedule[media_no] = { }
		count = int(round(count))
		self.schedule[media_no][ad_no] = self.schedule[media_no].get(ad_no, 0) + count
		self.ad_list.impression[ad_no] -= count

	def get_data(self):
		data = [ ]
		for media_no, ads in self.schedule.items():
			media = { }
			media['mediaNo'] = media_no
			media['adPutRequest'] = [ ]
			for ad_no, count in ads.items():
				media['adPutRequest'].append({ 'adNo': ad_no, 'putCount': count})
			data.append(media)
		return { 'data': data }
	
	def get_fill_ratio(self, media_no):
		if media_no not in self.schedule: return 0.0
		total, free = 0, 0
		for ad_no, count in self.schedule[media_no].items():
			total += count
			if self.ad_list.cost[ad_no] == 0:
				free += count
		return 100.0 * (total - free) / total

class ScheduleResult:
	def __init__(self, data):
		self.turn_no = data.get('turnNo', None)
		self.time_seq = data.get('timeSeq', None)
		self.result = { }
		for result in data['data']:
			media_no = result['mediaNo']
			if media_no not in self.result:
				self.result[media_no] = { }
			for ad in result['adClickResult']:
				ad_no = ad['adNo']
				ad_click = ad['clickCount']
				self.result[media_no][ad_no] = ad_click

	def get_media_clicks(self):
		media_clicks = { }
		for media_no, ads in self.result.items():
			for ad_no, count in ads.items():
				media_clicks[media_no] = media_clicks.get(media_no, 0) + count
		return media_clicks
	
	def gains(self, ad_list):
		gain = 0
		for media_no, ads in self.result.items():
			for ad_no, count in ads.items():
				gain += ad_list.cost[ad_no] * count
		return gain 


class AdAPI:
	def __init__(self):
		self.connection = httplib.HTTPSConnection("adsche.skplanet.com")
		self.headers = {
			"Content-type": "application/json", 
			"X-Auth-Token": '398792cb634dbc6bf413fe8e6676a43a',
		}

	def _request(self, method, url, body=None):
		self.connection.request(method, url, headers=self.headers, body=body)
		resp = self.connection.getresponse().read()
		data_json = json.loads(resp)
		error = data_json.get('error', None)
		if error:
			raise Exception('RequestError: %d - %s' % (error['code'], error['message']))
		return data_json

	def start_new_turn(self):
		data = self._request('GET', '/api/startNewTurn')
		return data

	def get_ad_list(self):
		data = self._request('GET', '/api/adList')
		return data

	def get_media_list(self):
		data = self._request('GET', '/api/mediaList')
		return data

	def post_schedule(self, sche):
		data = self._request('POST', '/api/schedule', json.dumps(sche))
		return data


def main(local_mode=True):
	api = AdAPI()
	api.start_new_turn()

	ad_list = AdList(api.get_ad_list())
	media_list = MediaList(api.get_media_list())
	#print ad_list.cost
	#print ad_list.impression
	#print media_list.max_impression
	#print media_list.fill_ratio
	#print ad_list.time_seq

	ad_score = AdScore(ad_list, media_list)

	if local_mode:
		for x, imp in ad_list.impression.items():
			ad_list.impression[x] = { 200: 25000000, 100: 50000000, 10: 250000000, 1: 500000000, 0: 100000000 }[ad_list.cost[x]]
		test_gain = 0
		lines = open('media_count_v2_2','r').readlines()


	# get max_impression_scale
	sum_free_ads = sum(map(lambda x: ad_list.impression[x], filter(lambda x: ad_list.cost[x] == 0, ad_list.get_ads())))
	sum_paid_ads = sum(map(lambda x: ad_list.impression[x], filter(lambda x: ad_list.cost[x] != 0, ad_list.get_ads())))
	sum_need_free = 0
	sum_need_paid = 0
	need_free = { }
	need_paid = { }
	for media_no in media_list.get_media_ids():
		need_free[media_no] = (1.0 - 0.01 * media_list.fill_ratio[media_no]) * media_list.max_impression[media_no] * 10000
		need_paid[media_no] = (0.01 * media_list.fill_ratio[media_no]) * media_list.max_impression[media_no] * 10000
		sum_need_free += need_free[media_no]
		sum_need_paid += need_paid[media_no]
	sum_need_paid = sum(need_paid.values())
	sum_need_free = sum(need_free.values())
	# print sum_free_ads, sum_paid_ads, 1.0 * sum_free_ads / sum_paid_ads
	# print sum_need_free, sum_need_paid
	max_impression_scale = min(1.0, sum_paid_ads / sum_need_paid)
	# print '# max_impression_scale =', max_impression_scale
	# print max_impression_scale * sum_need_free, max_impression_scale * sum_need_paid

	for media_no in need_free:
		need_free[media_no] = int(round(need_free[media_no] * max_impression_scale))
		need_paid[media_no] = int(round(need_paid[media_no] * max_impression_scale))

	#print need_free
	#print need_paid

	click_prob = cPickle.load(open("click_prob.dat", "rb"))
	prev_media_clicks = cPickle.load(open('initial_clicks.dat', 'rb'))

	# 200: 0.03030303030303
	# 100: 0.06060606060606
	# 10 : 0.3030303030303
	#  1 : 0.60606060606061

	# main loop
	for seq in xrange(10000):
		if local_mode:
			#print seq, test_gain, ad_list.impression
			pass
		else:
			time.sleep(0.15)
			pass

		schedule = Schedule(ad_list, media_list)
		for media_id in media_list.get_media_ids():
			alpha = max_impression_scale
			#if seq < 6000 or filter(lambda x: x > 1200, prev_media_clicks): alpha = 0.98
			#ads = ad_list.get_paid_ad(click_prob[prev_media_clicks[media_id-1]], paid_cnt, alpha)
			if alpha < 1.01 and filter(lambda x: x > 0.061 * media_list.max_impression[media_id], prev_media_clicks): 
				alpha = 1.05
				old_max_impression_scale = max_impression_scale
				#max_impression_scale = 1.0
			if alpha > 1.01 and not filter(lambda x: x > 0.061 * media_list.max_impression[media_id], prev_media_clicks): 
				max_impression_scale = old_max_impression_scale
			if seq > 7500: # 크리 터지지 않을 경우 7000부터. 8000에서는 뒤에 짤림
				alpha = 1.05

			#if sum(map(lambda x: x[1], filter(lambda x: x[0] == 200, ad_list.impression.items()))) == 0:
			#	alpha = 1.08
			#if sum(map(lambda x: x[1], filter(lambda x: x[0] == 100, ad_list.impression.items()))) == 0:
			#	alpha = 2.35

			media_max_impression = int(round(media_list.max_impression[media_id] * max_impression_scale))
			free_cnt = min(need_free[media_id], media_max_impression)
			paid_cnt = max(0, media_max_impression - free_cnt)
			
			need_free[media_id] -= free_cnt
			need_paid[media_id] -= paid_cnt

			#\free_cnt = int(round((1 - 0.01 * media_list.fill_ratio[media_id]) * media_list.max_impression[media_id] * max_impression_scale))
			#paid_cnt = int(round(0.01 * media_list.fill_ratio[media_id] * media_list.max_impression[media_id] * max_impression_scale))
			if paid_cnt > 0:
				cpr = 1.0 * prev_media_clicks[media_id-1] / media_list.max_impression[media_id] #* max_impression_scale
				ads = ad_list.get_paid_ad2(cpr, paid_cnt, alpha)

				if len(ads) == 0: break
				for ad_no, cnt in ads:
					schedule.add(media_id, ad_no, cnt)
			
			#print free_cnt, paid_cnt, media_list.max_impression[media_id]
			if free_cnt > 0:
				candi = filter(lambda x: ad_list.impression[x] >= free_cnt, ad_list.get_free_ads())
				ad_no = random.choice(candi)
				schedule.add(media_id, ad_no, free_cnt)

		if local_mode:
			# for test
			if seq >= len(lines): break
			prev_media_clicks = [int(x) for x in lines[seq].strip().split()[4:]]
			req_sum = 0
			for media_no, ads in schedule.schedule.items():
				media_max_impression = int(round(media_list.max_impression[media_no] * max_impression_scale))
				all_ad_count = sum(ads.values())
				cpr = 1.0 * prev_media_clicks[media_no-1] / media_max_impression
				for ad_no, cnt in ads.items():
					click = int(round(1.0 * cpr * cnt))
					profit = ad_list.cost[ad_no] * click
					test_gain += profit
					req_sum += profit
			ad_score.add_ad_count(schedule.schedule)
			ad_score.add_profit(req_sum)

			print '%4d %10d %8d %5.1f ' % (seq, ad_score.get_score(), req_sum, ad_score.get_fr_sum()), 
			for x in prev_media_clicks:
				print '%4d ' % x,
			print
			sys.stdout.flush()

		else:
			# for submit 
			schedule_response = api.post_schedule(schedule.get_data())
			schedule_result = ScheduleResult(schedule_response)
			prev_media_clicks = map(lambda x: int(round(x / max_impression_scale)), schedule_result.get_media_clicks().values())
			#print schedule.schedule
			#print schedule_response
			#print schedule_result.result
			#print schedule_result.gains(ad_list, media_list, schedule)
			ad_score.add_ad_count(schedule.schedule)
			ad_score.add_profit(schedule_result.gains(ad_list))

			print '%4d %10d %8d %5.1f ' % (schedule_result.time_seq+1, ad_score.get_score(), schedule_result.gains(ad_list), ad_score.get_fr_sum()), 
			for x in schedule_result.get_media_clicks().values():
				print '%4d ' % x,
			print
			sys.stdout.flush()

	if local_mode:
		print >> sys.stderr, "Score = {:,}".format(test_gain)
		print >> sys.stderr, ad_score.get_score(), test_gain, ad_score.get_fr_sum()
		print >> sys.stderr, ad_list.impression
	else:
		print ad_list.cost
		print ad_list.impression
		print media_list.max_impression
		print sum_need_free, sum_need_paid
		print max_impression_scale * sum_need_free, max_impression_scale * sum_need_paid

if __name__ == "__main__":
	main(local_mode=False)

