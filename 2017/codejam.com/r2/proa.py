print '100'
for i in xrange(100):
    print '100 4'
    foo = ''
    for j in xrange(100):
        if len(foo)!=0:
            foo += ' '
        foo += str(j+1)
    print foo
