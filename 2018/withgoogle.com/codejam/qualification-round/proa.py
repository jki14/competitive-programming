def lowbit(x):
    return x&-x

def higcount(x):
    p = 0
    while x>0:
        x >>= 1
        p += 1
    return p

def process():
    d, p = raw_input().strip().split()
    d = int(d)
    n = len(p)
    a = 0
    b = [0 for i in xrange(n)]
    c = 0
    s = 0
    for i in xrange(n):
        a <<= 1
        if p[i]=='S':
            a |= 1
            b[i] = c
            s += 1<<c
        else:
            c += 1
    if (n-c)>d:
        return 'IMPOSSIBLE'
    foo = 0
    while s>d:
        bar = a & (~(a+lowbit(a)))
        p = n - higcount(bar)
        x = (bar + lowbit(bar))>>1
        a ^= x | (x<<1)
        b[p-1] = b[p] -1
        s += (1<<b[p-1]) - (1<<b[p])
        foo += 1
    return str(foo)

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        print 'Case #%d: %s' % (i+1, process())

if __name__ == '__main__':
    main()
