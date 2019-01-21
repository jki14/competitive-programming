def gcd(x, y):
    while y!=0:
        x, y = y, x%y
    return x

def process():
    n = int(raw_input().strip())
    if n%2 == 0:
        print str(n)+' '+str(n)+' '+str(n>>1)
        return
    for x in xrange(max(n>>1, 1), 3501):
        for y in xrange(x, 3501):
            b = n*x*y
            a = 4*x*y-n*x-n*y
            if a>0 and (b%a)==0:
                print str(x)+' '+str(y)+' '+str(b/a)
                return

process()
