
# -*- coding: utf-8 -*-
import sys
#reload(sys)
#sys.setdefaultencoding('utf-8')

import argparse
import os
import csv
import datetime
import random
import time
import math
import multiprocessing
try:
   import cPickle as pickle
except:
   import pickle
from collections import defaultdict

import numpy as np
from scipy.spatial import distance
from sklearn.preprocessing import normalize
from sklearn.neighbors import NearestNeighbors, KDTree, BallTree

# Item Feature 요소들을 관리
class Features:
    def __init__(self):
        self._count = 0
        self._dict = dict()
        pass

    def __getitem__(self, key):
        return self._dict[key]

    def add(self, key):
        if not key is None and not key in self._dict:
            self._dict[key] = self._count
            self._count += 1

    # 영화의 Feature들이 있을 때 vector를 생성해서 리턴
    def vector(self, keys=[]):
        vec = np.zeros(self._count)
        for w in keys:
            if w in self._dict:
                vec[self._dict[w]] = 1.0
        return vec

    @staticmethod
    def similarity(vec1, vec2):
        return distance.cosine(vec1, vec2)


# 가장 인기있는 영화들을 관리
class Popularity:
    def __init__(self):
        self._dict = defaultdict(int)

    def count(self):
        return len(self._dict)

    def add(self, x):
        self._dict[x] += 1

    def top(self, k):
        return sorted(self._dict.iteritems(), key=lambda x: -x[1])[:k]

    def top_set(self, k):
        return set([x[0] for x in self.top(k)])

    def threshold(self, k):
        return sorted([x for x in self._dict.iteritems() if x[1] > k], key=lambda x: x[1], reverse=True)


# 각 영화 아이템에 대한 클래스
class Item:
    def __init__(self, line, idx):
        tokens = line.strip().split('\t')
        self.idx = idx
        self.prod_id = tokens[0]
        #self.series_id = tokens[1]
        self.type_id = tokens[2]
        self.cate = tokens[3]
        self.title = tokens[4]
        self.synp = tokens[5]
        self.prod_year = int(tokens[6]) if len(tokens[6]) == 4 else 0
        tokens[7] = tokens[7].replace('.', '')
        yyyy, mm, dd = tokens[7][:4], tokens[7][4:6], tokens[7][6:]
        try:
            yyyy = max(int(yyyy), 1900)
        except:
            yyyy = 1900
        try:
            mm = max(int(mm), 1)
        except:
            mm = 01
        try:
            dd = max(int(dd), 1)
        except:
            dd = 01
        self.open_date = datetime.date(yyyy, mm, dd)
        #self.series_tm = tokens[8]
        self.directors = tokens[9].split(',')
        self.actors = tokens[10].split(',')
        self.genres = tokens[11].split(',')
        self.countries = tokens[12].split(',')
        self.level = int(tokens[13]) if tokens[13] else 0
        self.upload_date = datetime.date(*map(int,('20' + tokens[14]).split('/')))

        self.enable = True
        self.freed = False
        self.update_days = (datetime.date(2015, 3, 31) - self.upload_date).days
        self.last_price = -1
        self.date_prices = dict()
        self.date_view = dict()
        self.view_count = 0
        self.view_month = defaultdict(int)
        self.title_nouns = []#kkma.nouns(unicode(self.title, 'utf-8'))
        self.feat_year = self.prod_year
        # 제작년도를 1970, 1980, 1990, 2010 등 연대별로 분류
        if self.prod_year <= 0:
            self.feat_year = 0
        elif self.prod_year <= 1979:
            self.feat_year = 1970
        elif self.prod_year <= 1989:
            self.feat_year = 1980
        elif self.prod_year <= 1999:
            self.feat_year = 1990
        elif self.prod_year <= 2005:
            self.feat_year = 2000
        elif self.prod_year <= 2009:
            self.feat_year = 2005

    def is_movie(self):
        return self.type_id == 'FL'

    # 영화 특징을 나타내는 Features
    def features(self):
        return [self.level, self.prod_year] + self.countries + self.directors + self.genres

    def last_count(self):
        if not self.date_view: return 0
        return sorted(self.date_view.items(), key=lambda x: -x[0])[0][1]

    def __str__(self):
        return '\t'.join(map(str, [self.prod_id, self.level, self.prod_year, self.title, '/'.join(self.genres), self.view_count, self.last_price]))


# 구매기록 클래스
class Record:
    def __init__(self, line):
        tokens = line.strip().split('\t')
        self.user_id = tokens[0]
        self.date = datetime.date(*map(int,tokens[1].split('-')))
        self.prod_id = tokens[2]
        self.price = int(tokens[3])

    def __str__(self):
        return '%s\t%s\t%s\t%d' % (self.user_id, self.date, self.prod_id, self.price)


# 사용자 정보를 관리하는 클래스
class User:
    def __init__(self, user_id, idx):
        self.idx = idx
        self.user_id = user_id
        self.history = []
        self.watched_movies = set()
        self.maximum_level = -1
        self.maximum_price = -1

        self._vector_count = 0
        self._vector = None
        self._after_days = []
        self.view_month = defaultdict(int)

    def __str__(self):
        return ''

    # 구매 영화가 들어왔을 때 사용자의 User Preference Vector를 업데이트
    def update_vector(self, vec):
        self._vector_count += 1
        if self._vector is None:
            self._vector = np.array(vec)
        else:
            self._vector += (vec - self._vector) / self._vector_count

    def profile_vector(self):
        return self._vector

    def add_purchase(self, record, item):
        self.history.append(item.idx)
        self.maximum_level = max(self.maximum_level, int(item.level))
        self.maximum_price = max(self.maximum_price, int(record.price))
        self.watched_movies.add(item.idx)
        self._after_days.append((record.date - item.upload_date).days)
        self.view_month[record.date.month] += 1

    # 영화를 봤는지 확인, 이미 봤던 영화는 패스
    def watched(self, item_idx):
        return item_idx in self.watched_movies

    # 사용자의 최대 관람등급을 확인
    def check_level(self, level):
        if self.maximum_level == -1: return True
        return level <= self.maximum_level

    # 사용자의 최대 구매 가격을 확인
    def check_price(self, price):
        if self.maximum_price == -1: return True
        return price <= self.maximum_price


class Recommender:
    def __init__(self, items_tsv, records_tsv):
        # 영화 아이템 입력 및 분석
        start = time.time()
        self._movie_items_list = []
        self._movie_items_table = dict()
        for line in open(items_tsv):
            item = Item(line, len(self._movie_items_list))
            if item.update_days < 0: continue
            if item.is_movie():
                self._movie_items_list.append(item)
                self._movie_items_table[item.prod_id] = item.idx

        assert len(self._movie_items_list) == len(self._movie_items_table)
        print '-- Initalize movie items (%d) : %f secs' % (len(self._movie_items_list), time.time() - start)

        self._users_list = []
        self._users_table = dict()

        # init movie records
        start = time.time()
        #self._movie_records = []
        self.popularities = defaultdict(Popularity)
        self.preferences = defaultdict(list)
        for line in open(records_tsv):
            record = Record(line)
            if record.user_id not in self._users_table:
                idx = len(self._users_list)
                self._users_list.append(User(record.user_id, idx))
                self._users_table[record.user_id] = idx
            user = self._users_list[self._users_table[record.user_id]]
            if record.prod_id in self._movie_items_table:
                #self._movie_records.append(record)
                item = self._movie_items_list[self._movie_items_table[record.prod_id]]
                if item.last_price > 0 and record.price == 0:
                    item.freed = True
                item.last_price = record.price
                item.view_count += 1
                item.view_month[record.date.month] += 1
                item.date_prices[record.date] = min(record.price, item.date_prices.get(record.date, record.price))
                item.date_view[record.date] = item.date_view.get(record.date, 0) + 1
                user.add_purchase(record, item)
                
                self.preferences[user.idx].append(item.idx)
            user.maximum_level = max(user.maximum_level, int(item.level))


        for rank, item in enumerate(sorted(self._movie_items_list, key=lambda x: -x.view_count)[:20]):
            print '-- rank=%d %d\t%d\t%s\t%s\n' % (rank, item.idx, item.view_count, item.prod_id, item.title)
            for x in sorted(item.date_prices.items(), key=lambda x: x[0])[-20:]:
                print '   ', x, (x[0] - item.upload_date).days, item.date_view[x[0]]


        for item in self._movie_items_list:
            for x in item.actors:
                self.popularities['actors'].add(x)
            for x in item.directors:
                self.popularities['directors'].add(x)
            for x in item.countries:
                self.popularities['countries'].add(x)
            for x in item.title_nouns:
                self.popularities['title'].add(x)

        print '\n-- actors    : ', self.popularities['actors'].count()
        for k, v in self.popularities['actors'].top(10):
            print '    %10d %s' % (v, k)
        print '\n-- directors : ', self.popularities['directors'].count()
        for k, v in self.popularities['directors'].top(10):
            print '    %10d %s' % (v, k)
        print '\n-- countries : ', self.popularities['countries'].count()
        for k, v in self.popularities['countries'].top(10):
            print '    %10d %s' % (v, k)


        # filter out
        top_countries = set([k for k, v in self.popularities['countries'].top(10)])
        for item in self._movie_items_list:
            if len(set(item.countries) & top_countries) == 0:
                item.enable = False

        '''
        # users statistics
        print '-- User Statistics'
        for user_idx, user in enumerate(self._users_list):
            if user._after_days:
                print ' after %d  %.3f %s' % (user_idx, sum(user._after_days) / len(user._after_days), user._after_days)
        '''

        print '-- Initialize movie records : %f secs' % (time.time() - start)
        print '-- Movie Items   = %d (%d ok)' % (len(self._movie_items_list), sum([1 for x in self._movie_items_list if x.enable]))
        print '-- Users         = %d' % (len(self._users_list))


    def train(self):
        # 각 아이템별 Feature 생성
        start = time.time()
        self.features = Features()
        # 출연 배우 빈도순으로 상위 512명을 Feature로 사용
        actors_set = self.popularities['actors'].top_set(512)
        # 감독 빈도순으로 상위 128명을 Feature로 사용
        directors_set = self.popularities['directors'].top_set(128)
        # 국가 빈도순으로 상위 4개를 Feature로 사용
        countries_set = self.popularities['countries'].top_set(4)
        title_set = self.popularities['title'].top_set(0)

        for item in self._movie_items_list:
            self.features.add(item.level)
            #self.features.add(item.feat_year)
            #self.features.add(item.last_price)
            for x in item.genres[:3]:
                self.features.add(x)
            for x in item.countries:
                if x in countries_set:
                    self.features.add(x)
            for x in item.directors:
                if x in directors_set:
                    self.features.add(x)
            for x in item.actors:
                if x in actors_set:
                    self.features.add(x)
            for x in item.title_nouns:
                if x in title_set:
                    self.features.add(x)

        print '-- Add Item Features : %f secs' % (time.time() - start)
        print '-- Item features size : %d' % (len(self.features.vector([])))

        # 각 아이템별 Feature Vector를 생성
        start = time.time()
        item_vector_size = self.features.vector([])
        self._movie_vectors = np.array([self.features.vector(item.features()) for item in self._movie_items_list])
        print '-- Calculate item vector : %f secs' % (time.time() - start)

        # User Preference Profile 생성
        start = time.time()
        for user_idx, user in enumerate(self._users_list):
            if user.history:
                for item_idx in user.history:
                    user.update_vector(self._movie_vectors[item_idx])
            else:
                user.update_vector(self.features.vector([]))

        print '-- Update user profile : %f secs' % (time.time() - start)

        # Nearest Neighbor를 구하기 위한 학습
        start = time.time()
        self._movie_nn = NearestNeighbors(n_neighbors=100, algorithm='brute', metric='cosine').fit(self._movie_vectors)
        self._movie_neighbors_distances, self._movie_neighbors_indices = self._movie_nn.kneighbors(self._movie_vectors)
        print '-- Nearest neibhbors : %f secs' % (time.time() - start)

    # 사용자가 이미 구매한 아이템 기준으로 Item Feature Vector를 비교해서 가장 유사한 아이템을 우선 추천
    def export_watched_neighbor_item(self, predict_csv):
        start = time.time()
        with open(predict_csv, 'w') as writer:
            for user_idx, user in enumerate(self._users_list):
                if user_idx % 100 == 0: 
                    print 'user ', user_idx

                popular_movies = sorted(range(len(self._movie_items_list)), key=lambda x: self._movie_items_list[x].view_count, reverse=True)

                #movie_similarity = np.array([1/(math.log(x.view_count+1)+1) for x in self._movie_items_list])
                movie_similarity = np.ones(len(self._movie_items_list))
                for item_idx in user.history:
                    indices = self._movie_neighbors_indices[item_idx]
                    distances = self._movie_neighbors_distances[item_idx]
                    for i in xrange(1, len(self._movie_neighbors_distances[item_idx])):
                        neigh_idx = indices[i]
                        neigh_dist = distances[i]
                        if movie_similarity[neigh_idx] > neigh_dist:
                            movie_similarity[neigh_idx] = neigh_dist
                candidate = sorted([(x, i) for i, x in enumerate(movie_similarity)])

                cnt = 0
                for distance, item_idx in candidate:
                    item = self._movie_items_list[item_idx]
                    if distance > 0.3: continue
                    if not item.enable: continue
                    if item.update_days > 100: continue
                    if user.watched(item_idx): continue
                    #if not user.check_price(item.last_price): continue
                    if not user.check_level(item.level): continue
                    writer.write('%s,%s,%f,%d,%d\n' % (user.user_id, item.prod_id, distance, item.update_days, item.view_count))
                    cnt += 1
                    if cnt >= 1: break

                if cnt == 0:
                    for item_idx in popular_movies:
                        item = self._movie_items_list[item_idx]
                        if user.watched(item_idx): continue
                        if not item.enable: continue
                        if not user.check_level(item.level): continue
                        writer.write('%s,%s,%f,%d,%d\n' % (user.user_id, item.prod_id, -1, item.update_days, item.view_count))
                        cnt += 1
                        break
                assert cnt > 0

        print '-- Recommend watched neighbor item : %f secs' % (time.time() - start)
        pass

    # 사용자가 이미 구매한 아이템을 기준으로 User Preference Vector를 구해서 가장 유사한 아이템을 우선해서 추천
    def export_user_similar_item(self, predict_csv):
        start = time.time()
        popular_movies = sorted(range(len(self._movie_items_list)), key=lambda x: self._movie_items_list[x].view_month.get(2, 0), reverse=True)
        with open(predict_csv, 'w') as writer:
            for user_idx, user in enumerate(self._users_list):
                if user_idx % 100 == 0: 
                    print 'user ', user_idx

                cnt = 0
                distances, indices = self._movie_nn.kneighbors(user.profile_vector())
                for distance, item_idx in zip(distances[0], indices[0]):
                    item = self._movie_items_list[item_idx]
                    #if distance > 0.3: continue
                    if not item.enable: continue
                    if user.watched(item_idx): continue
                    #if not user.check_price(item.last_price): continue
                    #if not user.check_level(item.level): continue
                    writer.write('%s,%s,%f,%d,%d\n' % (user.user_id, item.prod_id, distance, item.update_days, item.view_count))
                    cnt += 1
                    if cnt >= 1: break
                '''
                if cnt <= -1:
                    for item_idx in popular_movies:
                        item = self._movie_items_list[item_idx]
                        if user.watched(item_idx): continue
                        if not item.enable: continue
                        #if not user.check_level(item.level): continue
                        writer.write('%s,%s,%f,%d,%d\n' % (user.user_id, item.prod_id, -1, item.update_days, item.view_count))
                        cnt += 1
                        break
                #assert cnt > 0
                '''

        print '-- Recommend user similar movies : %f secs' % (time.time() - start)


    # 사람들이 현재까지 가장 많이 본 영화들 중에서 사용자가 이미 본 것을 제외하고 추천
    def export_user_popular_item(self, predict_csv):
        start = time.time()
        with open(predict_csv, 'w') as writer:
            for user_idx, user in enumerate(self._users_list):
                if user_idx % 100 == 0: 
                    print 'user ', user_idx

                movie_similarity = np.array([1/(math.log(x.view_count+1)+1) for x in self._movie_items_list])
                candidate = sorted([(x, i) for i, x in enumerate(movie_similarity)])
                cnt = 0
                for distance, item_idx in candidate:
                    item = self._movie_items_list[item_idx]
                    if user.watched(item_idx): continue
                    writer.write('%s,%s,%f,%d,%d\n' % (user.user_id, item.prod_id, distance, item.update_days, item.view_count))
                    cnt += 1
                    if cnt >= 1: break

        print '-- Recommend popular item : %f secs' % (time.time() - start)
        pass


    # 2015년 2월 기준 박스오피스 누적관람객 상위 20개 영화 위주로 추천
    def export_latest_item(self, predict_csv):
        start = time.time()
        latest_items = sorted([x.idx for x in self._movie_items_list if x.feat_year >= 2014 and x.update_days > 10 and x.update_days < 60]) # Feb
        boxoffice = [ 
                # 2015년 2월기준 박스오피스 누적 순위 top 20
                # http://www.kobis.or.kr/kobis/business/stat/boxs/findMonthlyBoxOfficeList.do?loadEnd=0&searchType=search&sSearchYearFrom=2015&sSearchMonthFrom=1&sSearchYearTo=2015&sSearchMonthTo=2&sMultiMovieYn=&sRepNationCd=&sWideAreaCd=
                '국제시장',
                '인터스텔라',
                '님아, 그 강을 건너지 마오',
                '조선명탐정 : 사라진 놉의 딸',
                '킹스맨',
                '빅 히어로',
                '강남 1970',
                '오늘의 연애',
                '쎄시봉',
                '마다가스카의 펭귄',
                '이미테이션 게임',
                '박물관이 살아있다 : 비밀의 무덤',
                '허삼관',
                '그랜드 부다페스트 호텔',
                '도라에몽 : 스탠바이미(자막)',
                '내 심장을 쏴라',
                '아메리칸 스나이퍼',
                '주피터 어센딩',
                '개를 훔치는 완벽한 방법',
                '스폰지밥 3D']

        with open(predict_csv, 'w') as writer:
            for user_idx, user in enumerate(self._users_list):
                if user_idx % 1000 == 0: 
                    print 'user ', user_idx

                cnt = 0
                candidate = []
                user_vec = user.profile_vector()
                for item_idx in latest_items:
                    item = self._movie_items_list[item_idx]
                    if not item.enable: continue
                    if item.freed and item.last_price > 0: continue
                    #if '한국' not in item.countries: continue
                    if user.watched(item_idx): continue
                    candidate.append((Features.similarity(user_vec, self._movie_vectors[item_idx]), item_idx))
                    #candidate.append([item_idx, item_idx])

                cnt = 0
                for distance, item_idx in sorted(candidate):
                    if cnt >= 1: break
                    item = self._movie_items_list[item_idx]
                    if distance > 0.5: continue
                    if item.title not in boxoffice: continue
                    writer.write('%s,%s\n' % (user.user_id, item.prod_id))
                    cnt += 1

                for distance, item_idx in sorted(candidate):
                    if cnt >= 1: break
                    item = self._movie_items_list[item_idx]
                    writer.write('%s,%s\n' % (user.user_id, item.prod_id))
                    #writer.write('%s,%s,%f,%d,%d\n' % (user.user_id, item.prod_id, distance, item.update_days, item.view_count))
                    cnt += 1

        print '-- Recommend latest item : %f secs' % (time.time() - start)
        pass

    # 2월 말일 기준 가장 인기있는 아이템을 위주로 추천
    def export_current_hot_item(self, predict_csv):
        start = time.time()
        candidate = []
        for item_idx, item in enumerate(self._movie_items_list):
            if item.freed: continue
            if not item.enable: continue
            if item.update_days > 200: continue
            candidate.append(item_idx)
        print 'candidate = %d / %d' % (len(candidate), len(self._movie_items_list))

        candi_vectors = np.array([self.features.vector(self._movie_items_list[item_idx].features()) for item_idx in candidate])
        nn = NearestNeighbors(n_neighbors=100, algorithm='brute', metric='cosine').fit(candi_vectors)

        with open(predict_csv, 'w') as writer:
            for user_idx, user in enumerate(self._users_list):
                if user_idx % 10000 == 0: 
                    print 'user ', user_idx

                distances, indices = nn.kneighbors(user.profile_vector())
                cnt = 0
                for distance, idx in zip(distances[0], indices[0]):
                    item_idx = candidate[idx]
                    item = self._movie_items_list[item_idx]
                    #if distance > 0.3: continue
                    if not item.enable: continue
                    if user.watched(item_idx): continue
                    #if not user.check_price(item.last_price): continue
                    #if not user.check_level(item.level): continue
                    writer.write('%s,%s,%f,%d,%d\n' % (user.user_id, item.prod_id, distance, item.update_days, item.view_count))
                    cnt += 1
                    if cnt >= 2: break
                '''                
                if cnt <= -1:
                    for i in popular_movies:
                        item_idx = candidate[item_idx]
                        item = self._movie_items_list[item_idx]
                        if user.watched(item_idx): continue
                        if not item.enable: continue
                        #if not user.check_level(item.level): continue
                        writer.write('%s,%s,%f,%d,%d\n' % (user.user_id, item.prod_id, -1, item.update_days, item.view_count))
                        cnt += 1
                        break
                #assert cnt > 0
                '''
        print '-- Recommend current hot item : %f secs' % (time.time() - start)
        pass


    # 분석적으로 찾아낸 특정 영화를 우선 추천
    def export_trick_item(self, predict_csv):
        with open(predict_csv, 'w') as writer:
            for user_idx, user in enumerate(self._users_list):
                if user_idx % 10000 == 0: 
                    print 'user ', user_idx
                writer.write('%s,%s\n' % (user.user_id, '02310017058')) # 강남 1970
                #writer.write('%s,%s\n' % (user.user_id, '02310012691')) # 인터스텔라 


if __name__ == '__main__':
    submit_mode = 1
    items_tsv_path = '../rsc/round2_itemInfo.tsv'
    if submit_mode:
        records_tsv_path = '../rsc/round2_purchaseRecord.tsv'
    else:
        records_tsv_path = '../rsc/train_records.tsv'

    recommender = Recommender(items_tsv_path, records_tsv_path)
    recommender.train()

    #recommender.export_watched_neighbor_item('./predict.csv')
    #recommender.export_user_similar_item('./predict.csv')
    #recommender.export_latest_item('./predict.csv')
    #recommender.export_current_hot_item('./predict.csv')
    recommender.export_trick_item('./predict.csv')

    #Recommender(items_tsv_path, './data/test_records.tsv', items_pkl=False, records_pkl=False).export_movie_records('./data/test_movie_records.tsv')

