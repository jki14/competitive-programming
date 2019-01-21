def gcd(x, y):
    if y==0:
        return x
    return gcd(y, x%y)

def f(x):
    if x==1:
        return 1
    foo = 0
    for i in xrange(1, x):
        j = x-i
        if gcd(i, j)==1:
            foo += 1
    return foo

def g(x):
    foo=0
    for i in xrange(1, x+1):
        if x%i==0:
            foo += f(i)
    return foo

def e(x, k):
    if k==1:
        return f(g(x))
    if k%2==0:
        return g(e(x, k-1))
    return f(e(x, k-1))

#while True:
#    x, k=[int(i) for i in raw_input().split()]
#    print e(x, k)

#for k in xrange(1, 17):
#    buf = ''
#    for x in range(1, 17):
#        buf += ','+str(e(x, k))
#    print buf

i = 0

while True:
    if g(i)!=i:
        print 'g('+str(i)+')='+str(g(i))
    i += 1
