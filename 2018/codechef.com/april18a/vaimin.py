def main():
    p, q, c, m = [int(i) for i in raw_input().strip().split()]
    g = [[True for i in xrange(p+1)] for i in xrange(p+q+1)]
    for i in xrange(m):
        x, y = [int(j) for j in raw_input().strip().split()]
        if x+y<=p+q and x>=y:
            g[x+y][x] = False
    f = [[0 for i in xrange(p+1)] for i in xrange(p+q+1)]
    f[0][0] = 1
    for i in xrange(p+q):
        for j in xrange(min(i+1, p+1)):
            k = i-j
            if g[i][j] and j<=p and k<=q:
                # do good
                if j<p:
                    f[i+1][j+1] = (f[i+1][j+1] + f[i][j]) % 1000000007
                # do bad
                if k<q and j-k>c:
                    f[i+1][j] = (f[i+1][j] + f[i][j]) % 1000000007
    foo = 0
    if g[p+q][p]:
        foo = (f[p+q][p] % 1000000007 + 1000000007) % 1000000007
    print foo

if __name__ == '__main__':
    main()
