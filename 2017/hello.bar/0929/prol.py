#import numpy
#import fractions

def GCD(x, y):
    while(y!=0):
        (x, y) = (y, x%y)
    return x

case_num = int(raw_input())

#f = numpy.zeros(128, dtype='object')
#g = numpy.zeros(128, dtype='object')
#p = numpy.zeros(128, dtype='object')

f = [0] * 128
g = [0] * 128
p = [0] * 128

p[0] = 1
p[1] = 1
for i in xrange(2, 128):
    p[i] = p[i-1] * i

for case_idx in xrange(case_num):
    x, y = [int(x) for x in raw_input().split()]
    f[0] = 1
    g[0] = 0
    for i in xrange(y):
        f[i+1] = f[i] * (y-i)
        g[i+1] = f[i] * x * p[x+y-i-1]
    g[y+1] = f[y] * x * p[x-1]
    lef = 0
    rig = 0
    for i in xrange(y+2):
        if (i&1)==1:
            lef += g[i]
        rig += g[i]
    #gcd = fractions.gcd(lef, rig)
    gcd = GCD(lef, rig)
    lef /= gcd
    rig /= gcd
    print str(lef)+'/'+str(rig)
