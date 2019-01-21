for k in xrange(1, 10):
    foo = ''
    cur = 0
    for x in xrange(1, 10):
        cur += x**k
        if len(foo)>0:
            foo += ','
        foo += str(cur)
    print foo
