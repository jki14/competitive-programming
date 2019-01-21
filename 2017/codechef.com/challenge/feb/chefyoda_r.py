def count(s):
    r = 0
    c = 1
    while True:
        if c>s:
            break
        if (s&c)!=0:
            r += 1
        c <<= 1
    return r

for k in range(1, 6):
    for p in xrange(k+1):
        print '2 3 '+str(p)+' '+str(k)
        #x = 0
        #y = 0
        #for s in xrange(1<<k):
        #    y += 1
        #    if count(s)>=p:
        #        x += 1
        #print x*1./y
