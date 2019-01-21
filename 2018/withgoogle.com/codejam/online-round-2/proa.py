import numpy as np

def process(caseId):
    n = int(raw_input().strip())
    b = [int(i) for i in raw_input().strip().split()]
    a = [1 for i in xrange(n)]
    c = [0 for i in xrange(n)]
    if sum(a)!=sum(b):
        print('Case #%d: IMPOSSIBLE' % (caseId))
        return
    h = 0
    for i in xrange(n):
        if i==n-1 and a[i]!=b[i]:
            print('Case #%d: IMPOSSIBLE' % (caseId))
            return
        if a[i]>b[i]:
            c[i] = b[i] - a[i]
            a[i] += c[i]
            a[i+1] -= c[i]
        elif a[i]<b[i]:
            c[i+1] = b[i] - a[i]
            a[i] += c[i+1]
            a[i+1] -= c[i+1]
            #for j in xrange(c[i+1]):
            #    a[i+j+1] -= 1
        #print 'a = %s' %  str(a)
        #print 'b = %s' %  str(b)
        #print 'c = %s' %  str(c)
        h = max(h, abs(c[i]))
    if c[0]!=0 or c[-1]!=0:
        print('Case #%d: IMPOSSIBLE' % (caseId))
        return
    h += 1
    g = [['.' for i in xrange(n)] for j in xrange(h)]
    for j in xrange(n):
        if c[j]>0:
            for i in xrange(c[j]):
                g[i][j] = '/'
        elif c[j]<0:
            for i in xrange(-c[j]):
                g[i][j] = '\\'
    #for i in xrange(h):
    #    for j in xrange(n-1):
    #        while g[i][j]=='\\' and g[i][j+1]=='/':
    #            pass
    print('Case #%d: %d' % (caseId, h))
    for i in xrange(h):
        print ''.join(g[i])

def main():
    t = int(raw_input().strip())
    for i in xrange(t):
        process(i+1)

if __name__ == '__main__':
    main()
