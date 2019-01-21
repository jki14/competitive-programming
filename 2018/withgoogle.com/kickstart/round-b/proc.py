def process():
    #input
    n, v0, h0, a, b, c, d, e, f, m =[int(i) for i in raw_input().strip().split()]
    x = [0 for i in xrange(n)]
    y = [0 for i in xrange(n)]
    x[0] = v0
    y[0] = h0
    for i in xrange(1, n):
        x[i] = (a * x[i-1] + b * y[i-1] + c) % m
        y[i] = (d * x[i-1] + e * y[i-1] + f) % m
    #init
    groupByX = {}
    groupByY = {}
    for i in xrange(n):
        if x[i] not in groupByX:
            groupByX[x[i]] = 1
        else:
            groupByX[x[i]] += 1
        if y[i] not in groupByY:
            groupByY[y[i]] = 1
        else:
            groupByY[y[i]] += 1
    xmap = sorted(groupByX.iteritems())
    ymap = sorted(groupByX.iteritems())
    print xmap
    print ymap
    #process
    foo = 0
    for key, value in cntX.iteritems(): 
        foo += value * (value-1) * (value-2) / 6
        foo += value * (value-1) / 2 * (n - value)
    for key, value in cntY.iteritems(): 
        foo += value * (value-1) * (value-2) / 6
        foo += value * (value-1) / 2 * (n - value)
    for i in xrange(n):
        foo -= (cntX[x[i]] - 1) * (cntY[y[i]] - 1)
    return foo

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        print 'Case #'+str(i+1)+': '+str(process())

if __name__ == '__main__':
    main()
