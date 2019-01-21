while True:
    k = 0
    try:
        k = int(raw_input())
    except Exception:
        break
    foo = [0]*100
    goo = [0]*100
    for i in xrange(100):
        r = 0
        c = i+1
        while c>k:
            #print 'c='+str(c)
            if (c&1)==0:
                c /= 2
            else:
                c += k
            r += 1
        #print 'f['+str(i+1)+']='+str(r)
        foo[i] = r
        goo[i] = c
    print foo
    #print goo
    print sum(foo)
