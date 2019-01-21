def process():
    s, k = [int(i) for i in raw_input().strip().split()]
    r = []
    for x in xrange(10**k):
        if (x%s)==0:
            c = [0 for i in xrange(10)]
            for d in ('%05d' % (x)):
                c[ord(d)-ord('0')] ^= 1
            if len([i for i in xrange(10) if c[i]==1])<=1:
                r.append(str(x))
    print '\n'.join(r)
    print 'len = %d' % len(r)

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        process()

if __name__ == '__main__':
    main()
