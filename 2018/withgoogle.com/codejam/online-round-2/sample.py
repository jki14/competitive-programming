import numpy as np

def process(caseId):
    n = int(raw_input().strip())
    b = [int(i) for i in raw_input().strip().split()]
    a = [1 for i in xrange(n)]
    if sum(a)!==sum(b):
        print('Case #%d: IMPOSSIBLE\n' % (caseId))
        return
    h = 0
    for i in xrange(n):
        if a[i]>b[i]:
            c[i] = b[i] - a[i]
            a[i+1] -= c[i]
        else:
            c[i+1] = b[i] - a[i]
            for j in xrange(c[i]):
                a[i+j] -= 1
        h = max(h, abs(c[i]))
    if c[0]!=0 or c[-1]!=0:
        print('Case #%d: IMPOSSIBLE\n' % (caseId))
        return
    h += 1
    g = ['.' * n for j in xrange(h)]
    for j in xrange(n):
        if c[j]>0:
            for i in xrange(c[j]):
                g[i][j] = '/'
        elif c[j]<0:
            for i in xrange(-c[j]):
                g[i][j] = '\\'
    print('Case #%d: %d\n' % (caseId, h))
    for i in xrange(h):
        print g[i]

def main():
    t = int(raw_input().strip())
    for i in xrange(t):
        process(i+1)

if __name__ == '__main__':
    main()
