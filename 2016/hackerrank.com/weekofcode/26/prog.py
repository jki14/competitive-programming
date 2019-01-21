import math

def core(p, n, floor, ceil, xor):
    if p == n:
        if xor == 0:
            return 0
        return 1
    foo = 0
    for x in range(floor, ceil):
        foo += core(p+1, n, x+1, ceil, xor^x)
    return foo

m = int(raw_input())

for n in xrange(8):
    cnt = core(0, n, 1, 2**m, 0)
    buf = math.factorial(n)
    print str(n)+' = '+str(cnt)+' * '+str(buf)+' = '+str(cnt*buf)
