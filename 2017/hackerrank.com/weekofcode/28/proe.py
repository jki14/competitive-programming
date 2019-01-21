import os

for k in xrange(60):
    print '30 30'
    foo = ''
    for i in xrange(30):
        if int(os.urandom(1).encode('hex'), 16)&1==0:
            foo+='W'
        else:
            foo+='B'
    print foo
