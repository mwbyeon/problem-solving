#-*- coding: utf-8 -*-

import math
import argparse
try:
    import cPickle as pickle
except:
    import pickle

words_freq = {}
words_sum = 0
segment_cache = {}


# 입력된 단어에 대해 두 개로 나누는 모든 분리 조합을 생성
def make_all_pairs(word, max_len=32):
   return [(word[:i+1], word[i+1:]) for i in range(min(len(word), max_len))]


# 단어 하나의 스코어를 계산
def word_prob(word):
	if word in words_freq:
		return float(words_freq[word]) / words_sum
	else:
		if len(word) == 1: return 1e-6 # 9160 / 10037 = 0.913 (0 errors)
		return 1.0 / (words_sum * 10**(len(word)))


# 단어 분리 결과의 스코어를 계산
def segment_prob(words):
	return sum(math.log(word_prob(w)) for w in words)


# 문자열을 여러 단어로 나눠서 리턴
def segment(word):
	# 중복된 입력의 단어 분리를 빠르게 하기 위해 cache 사용(memoization)
	if word in segment_cache:
		return segment_cache[word]
	if not word: return []

	# 입력 받은 문자열을 모든 경우의 수로 분리
	segmented = [[first] + segment(rest) for (first,rest) in make_all_pairs(word)]
	# 가장 높은 스코어를 갖도록
	result = max(segmented, key=segment_prob)
	# 결과를 재활용 하기 위해 cache에 저장
	segment_cache[word] = result
	return result


# 두 단어를 한 단어로 만들었을 때 점수가 더 높다면 합치기
def merge_words(segmented):
	result = []
	i = 0
	while i+1 < len(segmented):
		w1 = '%s %s' % (segmented[i], segmented[i+1])
		w2 = '%s%s' % (segmented[i], segmented[i+1])
		s1 = words_freq.get(w1, 0)
		s2 = words_freq.get(w2, 0)
		if s1 < s2:
			result.append(w2)
			i += 2
		else:
			result.append(segmented[i])
			i += 1
	if i < len(segmented):
		result.append(segmented[i])
	return result


# 한 단어를 두 단어로 분리 했을 떄 점수가 더 높다면 분리하기
def split_words(segmented):
	result = []
	for w in segmented:
		sc = words_freq.get(w, 0)
		w1, w2 = None, None
		for i in xrange(1, len(w)-1):
			ww = '%s %s' % (w[:i], w[i:])
			if words_freq.get(ww, 0) > sc:
				sc = words_freq[ww]
				w1 = w[:i]
				w2 = w[i:]

		if w1 and w2:
			result.append(w1)
			result.append(w2)
		else:
			#result += split_words3(w)
			result.append(w)

	return result


# 입력된 문자열을 분리해서 반환
def predict(s):
	global words_freq
	# 단어 출현 확를의 합이 최대가 되도록 분리
	segmented = segment(s) # 8533 / 10037 = 0.850 (0 errors)
	# 단어를 합치기
	merged = merge_words(segmented)
	# 단어를 분리
	splitted = split_words(merged)	# 9075 / 10037 = 0.904 (0 errors)
	return ' '.join(splitted)


# train.qry 입력으로부터 결과를 평가
def evaluate(args):
	load()
	word_score = 0
	word_total = 0
	word_error = 0
	char_score = 0
	char_total = 0

	if args.output:
		output_fp = open(args.output, 'w')
	for line in open(args.input).readlines():
		query, answer = line.strip().split('\t')
		output = predict(query)
		if args.output:
			f.write('%s [%s] [%s]\n' % ('PASS' if output == answer else 'FAIL', output, answer))
		
		if output == answer:
			word_score += 1
		elif len(filter(lambda x: x.isalpha(), output)) != len(filter(lambda x: x.isalpha(), answer)):
			word_error += 1
			print output, answer
		else:
			print '[%s] [%s]' % (answer, output)
			pass
		char_score += len(query) - abs(len(output) - len(answer))
		char_total += len(query)
		word_total += 1
	qa = 1.0 * word_score / word_total
	ca = 1.0 * char_score / char_total
	
	print 
	print '%6d / %6d = %.4f (%d errors)' % (word_score, word_total, qa, word_error)
	print '%6d / %6d = %.4f ' % (char_score, char_total, ca)
	print 
	print '%.4f + %.4f = %.4f\n' % (qa, ca, (qa+ca)*0.5)


# 모델 파일로부터 데이터를 로드
def load():
	global words_freq
	global words_sum
	words_freq = pickle.load(open(args.model, "rb"))
	for key, value in words_freq.items():
		if ' ' not in key:
			words_sum += value


# 테스트
def test(args):
	load()
	with open(args.output, 'w') as f:
		for line in open(args.input).readlines():
			query = line.strip()
			output = predict(query)
			assert(len(filter(lambda x: x.isalpha(), output)) == len(filter(lambda x: x.isalpha(), query)))
			f.write('%s\n' % output)


# 불필요한 문자 제거 및 치환
def remove_characters(s):
	# 소문자로
	s = s.lower()
	
	# 've, 't, 'd 와 같은 건 없애고 공백으로
	# 's' 추가 후: 0.914 + 0.992 = 0.953
	for x in ['ve', 't', 'd', 'll', 're', 'm', 's']:
		s = s.replace('\'%s ' % x, ' ')
	# quote는 공백으로
	s = s.replace('\'', ' ').replace('\"', ' ')

	# 숫자와 문자, 공백만으로 된 문자열로 리턴
	s = ''.join(map(lambda x: x.lower() if x.isalpha() or x.isdigit() else ' ', s))
	return s


# train.txt로부터 모델 파일을 생성하기 위해 트레이닝
def train(args):
	words_freq = {}
	#train.qry도 학습에 사용 할 경우
	'''	
	for line in open('../oth/train.qry'):
		query, answer = line.strip().split('\t')
		splitted = answer.split()
		for i, w in enumerate(splitted):
			words_freq[w] = words_freq.get(w, 0) + 1
			# 두개의 단어를 합쳐서 사전에 추가
			if i > 0 and len(splitted[i]) > 1:
				ww = '%s %s' % (splitted[i-1], splitted[i])
				words_freq[ww] = words_freq.get(ww, 0) + 1
	'''
	
	for line in open(args.input).readlines():
		# 불필요한 문자 제거
		removed = remove_characters(line).split() 
		for i, w in enumerate(removed):
			# 각 단어에 대해 출현 빈도 증가
			words_freq[w] = words_freq.get(w, 0) + 1
			# 단어가 's' 로 끝난다면 복수형으로 인식해서 끝의 's'를 제거
			if len(w) > 4 and w.endswith('s'):
				if w[:-1] not in words_freq: words_freq[w[:-1]] = 1

			# 맨 앞이나 맨 뒤의 한 글자를 제거 한 후 사전에 추가
			if len(w) > 11:
				#words_freq[w[:-1]] = words_freq.get(w[:-1], 0) + 1
				#words_freq[w[1:]] = words_freq.get(w[1:], 0) + 1
				if w[:-1] not in words_freq: words_freq[w[:-1]] = 1
				if w[1:] not in words_freq: words_freq[w[1:]] = 1

			# 두개의 단어를 합쳐서 사전에 추가
			if i > 0 and len(removed[i]) > 1:
				ww = '%s %s' % (removed[i-1], removed[i])
				words_freq[ww] = words_freq.get(ww, 0) + 1

			# 중간의 인접한 두 문자를 서로 바꿔서 사전에 추가
			if len(w) > 5:
				for i in xrange(2, len(w)-1):
					char_list = list(w)
					char_list[i-1], char_list[i] = char_list[i], char_list[i-1]
					ww = ''.join(char_list)
					if ww not in words_freq: words_freq[ww] = 1

	# 정답셋에 나타나지 않는 한 글자 단어를 사전에서 제거
	for x in 'cdfghijmopqrstuwxz':
		if x in words_freq:
			del words_freq[x]

	# 단어 사전을 저장
	pickle.dump(words_freq, open(args.model, "wb"))
	
if __name__ == "__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument('-r', '--run', type=str, required=True, choices=['train', 'test', 'eval'])
	parser.add_argument('-i', '--input', type=str, required=True)
	parser.add_argument('-o', '--output', type=str)
	parser.add_argument('-m', '--model', type=str, required=True)
	args = parser.parse_args()

	if args.run == 'train':
		train(args)
	elif args.run == 'test':
		test(args)
	elif args.run == 'eval':
		evaluate(args)

