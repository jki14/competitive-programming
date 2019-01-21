def process():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    p = [a[i] for i in xrange(0, n, 2)]
    q = [a[i] for i in xrange(1, n, 2)]
    p = sorted(p)
    q = sorted(q)
    b = []
    for i in xrange(n):
        if (i&1)==0:
            b.append(p[i>>1])
        else:
            b.append(q[i>>1])
    for i in xrange(n-1):
        if b[i]>b[i+1]:
            return str(i)
    return 'OK'

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        print 'Case #%d: %s' % (i+1, process())

if __name__ == '__main__':
    main()
