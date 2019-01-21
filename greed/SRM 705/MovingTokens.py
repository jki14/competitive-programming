import os

n = 50
m = 50
print n
print m
print n*m
for i in xrange(n*m):
    print int(os.urandom(1).encode('hex'), 16) % n
print ""
print 0
