import sys

def lowbit(x):
    return x & (-x)

def add(a, m, x, y):
    i = x
    while i<=m:
        j = y
        while j<=m:
            a[i-1][j-1] += 1
            j += lowbit(j)
        i += lowbit(i)

def cnt(a, m, x, y):
    foo = 0
    i = x
    while i>0:
        j = y
        while j>0:
            foo += a[i-1][j-1]
            j -= lowbit(j)
        i -= lowbit(i)
    #sys.stderr.write('cnt(%d, %d) = %d\n' % (x, y, foo))
    return foo

def box(a, m, x0, y0, x1, y1):
    x0 = max(x0, 1)
    y0 = max(y0, 1)
    x1 = min(x1, m)
    y1 = min(y1, m)
    if x0<=x1 and y0<=y1:
        return cnt(a, m, x1, y1) - cnt(a, m, x0-1, y1) - cnt(a, m, x1, y0-1) + cnt(a, m, x0-1, y0-1)
    else:
        return 0

def process():
    #input
    n, v0, h0, a, b, c, d, e, f, m =[int(i) for i in raw_input().strip().split()]
    s = [(v0, h0) for i in xrange(n)]
    for i in xrange(1, n):
        s[i] = ((a * s[i-1][0] + b * s[i-1][1] + c) % m, (d * s[i-1][0] + e * s[i-1][1] + f) % m)
    s = [(s[i][0]+1, s[i][1]+1) for i in xrange(n)]
    s = sorted(s)
    #sys.stderr.write(str(s)+'\n')
    a = [[0 for i in xrange(m)] for j in xrange(m)]
    for p in s:
        add(a, m, p[0], p[1])
    foo = 0
    #cur = 0
    for i in xrange(n):
        for j in xrange(i+1, n):
            #cur += 1
            #if cur%1000 == 0:
            #    sys.stderr.write('%d\n' % cur)
            #sys.stderr.write('+ (%d, %d), (%d, %d)\n' % (s[i][0], s[i][1], s[j][0], s[j][1]))
            foo += n - 2
            # center-box
            d = (s[j][0]-s[i][0], abs(s[j][1]-s[i][1]))
            x0 = min(s[i][0], s[j][0]) #+ d[0] - max(d)
            y0 = min(s[i][1], s[j][1]) #+ d[1] - max(d)
            x1 = max(s[i][0], s[j][0]) #- d[0] + max(d)
            y1 = max(s[i][1], s[j][1]) #- d[1] + max(d)
            #sys.stderr.write('  - (%d, %d) => (%d, %d) %d\n' % (x0+1, y0+1, x1-1, y1-1, box(a, m, x0+1, y0+1, x1-1, y1-1)))
            foo -= box(a, m, x0+1, y0+1, x1-1, y1-1)
            # uncovered
            if s[i][0]!=s[j][0] and s[i][1]!=s[j][1]:
                if s[j][1]>s[i][1]:
                    foo -= box(a, m, 1, 1, s[i][0]-1, s[i][1]-1)
                    #sys.stderr.write('  - (%d, %d) => (%d, %d) %d\n' % (1, 1, s[i][0]-1, s[i][1]-1, box(a, m, 1, 1, s[i][0]-1, s[i][1]-1)))
                    foo -= box(a, m, s[j][0]+1, s[j][1]+1, m, m)
                    #sys.stderr.write('  - (%d, %d) => (%d, %d) %d\n' % (s[j][0]+1, s[j][1]+1, m, m, box(a, m, s[j][0]+1, s[j][1]+1, m, m)))
                else:
                    foo -= box(a, m, 1, s[i][1]+1, s[i][0]-1, m)
                    #sys.stderr.write('  - (%d, %d) => (%d, %d) %d\n' % (1, s[i][1]+1, s[i][0]-1, m, box(a, m, 1, s[i][1]+1, s[i][0]-1, m)))
                    foo -= box(a, m, s[j][0]+1, 1, m, s[j][1]-1)
                    #sys.stderr.write('  - (%d, %d) => (%d, %d) %d\n' % (s[j][0]+1, 1, m, s[j][1]-1, box(a, m, s[j][0]+1, 1, m, s[j][1]-1)))
    return foo/3
            
def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        print 'Case #'+str(i+1)+': '+str(process())
        sys.stdout.flush()

if __name__ == '__main__':
    main()
