import math

for n in range(3,32):
    print 'n='+str(n)
    top = math.fabs(math.sin(n/3.0)*2.0)+math.sin(n/3.0)
    print top
    x0 = -1.0
    y0 = -1.0
    z0 = -1.0
    x = 1.0
    while x < n*1.0:
        y = 1.0
        while x+y < n*1.0:
            z = n-x-y
            cur = math.sin(x) + math.sin(y) + math.sin(z)
            if cur>top:
                x0 = x
                y0 = y
                z0 = z
                top=cur
            y += n/1000.0
        x += n/1000.0
    print 'x0='+str(x0)
    print 'y0='+str(y0)
    print 'z0='+str(z0)
    print top
