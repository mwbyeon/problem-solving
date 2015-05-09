import operator
import math

def possible(cakes, T):
    for t in xrange(T):
        if T - t >= max(cakes):
            return True

        i = cakes.index(max(cakes))
        if cakes[i] == 9:
            p1, p2 = 6, 3
        else:
            p1 = cakes[i] / 2
            p2 = cakes[i] - p1
        cakes[i] = p1
        cakes.append(p2)
        #print T, ':', cakes
    return False
    
def main():
    for tc in xrange(input()):
        D = input()
        cakes = map(int, raw_input().split())

        res = -1
        for t in xrange(max(cakes)):
            if possible(cakes[:], t+1):
                res = t+1
                break
        print 'Case #%d: %d' % (tc+1, res)

if __name__ == "__main__":
    main()
