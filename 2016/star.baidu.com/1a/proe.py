import numpy

arr = numpy.array([0], dtype='i')
for k in range(2, 8):
    l = len(arr)
    arr=numpy.append(arr, [0])
    for i in xrange(l):
        arr=numpy.append(arr, arr[l-i-1]^1)
cur = 0
buf = ''
for i in xrange(len(arr)):
    if len(buf)>0:
        buf = buf+','
    cur+=arr[i]^1
    buf = buf+str(cur)
print buf
