n = 300000
m = 26

print n

for v in xrange(0, n-1):
    u = v/m
    x = chr(ord('a')+(v%m))
    print str(u+1)+' '+str(v+2)+' '+x
