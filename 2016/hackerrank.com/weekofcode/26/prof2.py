import math

for n in range(3,32):
    print 'n='+str(n)
    top = math.sin(n/3.0)*3.0
    print top
    x = 1.0
    while x < n*1.0:
        y = 1.0
        while x+y < n*1.0:
            z = n-x-y
            cur = math.sin(x) + math.sin(y) + math.sin(z)
            if cur>top:
                top=cur
            y += n/1000.0
        x += n/1000.0
    print top
