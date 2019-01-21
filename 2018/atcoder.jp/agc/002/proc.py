def cutSequence(piles, threshold):
    for i in xrange(len(piles)-1):
        if piles[i]+piles[i+1]>=threshold:
            return range(0, i)+range(len(piles)-2, i-1, -1)
    return []

def main():
    n, m = [int(x) for x in raw_input().strip().split()]
    a = [int(x) for x in raw_input().strip().split()]
    foo = cutSequence(a, m)
    if len(foo)==0:
        print 'Impossible'
    else:
        print 'Possible'
        for x in foo:
            print x+1

if __name__ == '__main__':
    main()
