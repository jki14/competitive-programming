import random

n, m = [int(x) for x in raw_input().split()]

print str(n)+' '+str(m)

for i in xrange(n):
    buf = ''
    for j in xrange(m):
        buf += str(random.randint(-250, 250))+' '
    print buf
