def process(x, a, k):
    n = len(x)
    f = range(0, n)
    for i in a:
        f[i], f[i+1] = f[i+1], f[i]
    #print 'f=%s' % str(f)
    b = 1
    while b<=k:
        if (k&b)!=0:
            t = [0 for i in xrange(n)]
            for i in xrange(n):
                t[i] = x[f[i]]
            x = [i for i in t]
            #print 'x=%s' % str(x)
        t = [0 for i in f]
        for i in xrange(n):
            t[i] = f[f[i]]
        f = [i for i in t]
        #print 'f=%s' % str(f)
        b <<= 1
    return x

def main():
    n = int(raw_input().strip())
    x = [int(i) for i in raw_input().strip().split()]
    for i in xrange(len(x)-1, 0, -1):
        x[i] = x[i]-x[i-1]
    m, k = [int(i) for i in raw_input().strip().split()]
    a = [int(i) for i in raw_input().strip().split()]
    for i in xrange(len(a)):
        a[i] -= 2
    r = process(x[1:], a, k)
    print x[0]
    for i in xrange(1, len(x)):
        x[i] = x[i-1]+r[i-1]
        print x[i]

if __name__ == '__main__':
    main()
