import os

T = 100

print T
for k in xrange(T):
    n = 20
    print n
    foo = int(os.urandom(4).encode('hex'), 16)
    row = ''
    for i in xrange(n):
        if len(row)>0:
            row += ' '
        if (foo&(1<<i))!=0:
            row += '1'
        else:
            row += '0'
    print row
