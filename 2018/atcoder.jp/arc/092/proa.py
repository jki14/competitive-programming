def find(u, c, p, v):
    n = len(c)
    if not v[u]:
        v[u] = True
        for q in xrange(n):
            if c[u][q]:
                if p[q]==-1 or find(p[q], c, p ,v):
                    p[q] = u
                    return True
    return False

def maxMatch(c):
    foo = 0
    n = len(c)
    p = [-1 for i in xrange(n)]
    for i in xrange(n):
        v = [False for j in xrange(n)]
        if find(i, c, p, v):
            foo += 1
    return foo

def process(r, b):
    n = len(r)
    c = [[False for i in xrange(n)] for j in xrange(n)]
    for i in xrange(n):
        for j in xrange(n):
            if r[i][0]<b[j][0] and r[i][1]<b[j][1]:
                c[i][j] = True
    return maxMatch(c)

def main():
    n = int(raw_input().strip())
    r = []
    b = []
    for i in xrange(n):
        x, y = [int(sub) for sub in raw_input().strip().split()]
        r.append((x, y))
    for i in xrange(n):
        x, y = [int(sub) for sub in raw_input().strip().split()]
        b.append((x, y))
    print process(r, b)

if __name__=='__main__':
    main()
