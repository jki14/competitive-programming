import numpy

def squared(x):
    lef = 0
    rig = 15
    while lef<=rig:
        mid = (lef+rig)>>1
        if mid*mid<=x:
            if mid==rig or (mid+1)*(mid+1)>x:
                return mid*mid==x
            lef = mid+1
        else:
            rig = mid-1
    return False

valid = numpy.empty([0, 0], dtype='i')

for x in xrange(-12, 13):
    for y in xrange(-12, 13):
        dist = x*x+y*y
        if squared(dist):
            continue
        valid = numpy.append(valid, dist)

valid[::-1].sort()

print valid.shape

print sum(valid.tolist()[:12])

print valid
