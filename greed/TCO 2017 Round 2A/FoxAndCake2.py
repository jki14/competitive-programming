import numpy as np

def gcd(x, y):
    if y==0:
        return x
    return gcd(y, x%y)

def solution(c, s):
    if gcd(c, s)!=1:
        return 1
    if (c&1)==1 and (s&1)==1:
        if c>3 and s>3:
            return 1
    else:
        if (c&1)!=1:
            #print 'c='+str(c)+' '+'s='+str(s)
            c, s= s, c
            #print 'c='+str(c)+' '+'s='+str(s)
        if c>3 and s>6:
            return 1
    return 0

foo = np.zeros((256, 256), dtype='i')
foo[0][0] = 1

for c in xrange(1, 256):
    for s in xrange(1, 256):
        for i in xrange(1, c+1):
            for j in xrange(1, s+1):
                if gcd(i, j)!=1 and foo[c-i][s-j]==1:
                    foo[c][s]=1
                    break
            if foo[c][s]==1:
                break
        if foo[c][s]!=solution(c, s):
            print 'E foo[%d][%d]=%d solution=%d' % (c, s, foo[c][s], foo[c][s]^1)
