
import sys
import random
import cPickle

data = []
initial_media_clicks = [0.0] * 40
add_count = 0
initial_range = 2500

max_impression = {1: 2000, 2: 2000, 3: 2000, 4: 2000, 5: 2000, 6: 2000, 7: 2000, 8: 2000, 9: 2000, 10: 2000, 11: 5000, 12: 5000, 13: 5000, 14: 5000, 15: 5000, 16: 5000, 17: 5000, 18: 5000, 19: 5000, 20: 5000, 21: 10000, 22: 10000, 23: 10000, 24: 10000, 25: 10000, 26: 10000, 27: 10000, 28: 10000, 29: 10000, 30: 10000, 31: 20000, 32: 20000, 33: 20000, 34: 20000, 35: 20000, 36: 20000, 37: 20000, 38: 20000, 39: 20000, 40: 20000}

for i, line in enumerate(open('media_count', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x, map(int, line[1:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]
            
for i, line in enumerate(open('media_count2', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x, map(int, line[1:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]

for i, line in enumerate(open('media_count3', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x, map(int, line[2:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]
    
for i, line in enumerate(open('media_count4', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x, map(int, line[2:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]

for i, line in enumerate(open('media_count5', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x, map(int, line[4:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]

for i, line in enumerate(open('media_count_v2_1', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x / 0.974889217134, map(int, line[4:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]

for i, line in enumerate(open('media_count_v2_2', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x / 0.974889217134, map(int, line[4:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]

for i, line in enumerate(open('media_count_v2_3', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x / 0.974889217134, map(int, line[4:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]

for i, line in enumerate(open('media_count_v2_6', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x / 0.974889217134, map(int, line[4:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]

for i, line in enumerate(open('media_count_v2_8', 'r')):
    line = line.strip().split()
    if not line or '0' in line: continue
    counts = filter(lambda x: x / 0.974889217134, map(int, line[4:]))
    data += [1.0 * counts[x] / max_impression[x+1] for x in xrange(len(counts))]
    if int(line[0]) < initial_range:
        add_count += 1
        for x in xrange(len(counts)):
            initial_media_clicks[x] += counts[x]

            
initial_media_clicks = map(lambda x: int(1.0 * x / add_count), initial_media_clicks)


print 'initial media clicks : ', initial_media_clicks
#cPickle.dump(rank, open("click_ratio.dat", "wb"))
cPickle.dump(initial_media_clicks, open('initial_clicks.dat', 'wb'))


#%matplotlib inline
import matplotlib.pyplot as plt

sum_data = sum(data)
accu = 0.0
rank = [0.0] * 101
for x in sorted(data):
    accu += x
    r = int(100.0 * accu / sum_data)
    rank[r] = x

print sum_data, accu

fig, ax1 = plt.subplots(figsize=(20,10))
plt.grid(True)
ax1.hist(data, bins=200, normed=True, cumulative=True)
plt.show()

fig, ax2 = plt.subplots(figsize=(20,10))
ax2.plot(range(len(rank)), rank)
plt.show()

print rank[39], rank[91], rank[97]
