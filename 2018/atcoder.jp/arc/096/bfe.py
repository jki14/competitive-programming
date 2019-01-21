for n in xrange(2, 6):
    a = [i for i in xrange(2**n)]
    k = len(a)
    foo = 0
    for s in xrange(2**k):
        cnt = [0 for i in xrange(n)]
        for i in xrange(k):
            if (s&(1<<i))!=0:
                for j in xrange(n):
                    if (a[i]&(1<<j))!=0:
                        cnt[j] += 1
        if min(cnt)>=2:
            foo += 1
    print foo
