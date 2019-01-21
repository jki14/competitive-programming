import numpy

T = 10
print T
while T>0:
    T -= 1
    n = 10
    print str(n)+' 70'
    a = numpy.random.permutation(10)
    print str(a.tolist()).replace('[', '').replace(',', '').replace(']', '')
    for s in range(1, 6):
        x = 1
        while x+s-1<=n:
            x += 1
            y = x+s-1+1
            while y+s-1<=n:
                y += 1
                print str(x)+' '+str(x+s-1)+' '+str(y)+' '+str(y+s-1)
