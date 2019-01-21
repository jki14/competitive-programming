import numpy

f = numpy.zeros(50, dtype='int64')
f[0] = 1
for i in range(1, 50):
    for j in xrange(i):
        f[i]+=f[j]
print f
