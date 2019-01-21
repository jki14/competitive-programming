def main():
    n, m, q = [int(i) for i in raw_input().strip().split()]
    f = [[0 for j in xrange(n)] for i in xrange(n)]
    for i in xrange(m):
        l, r = [int(i) - 1 for i in raw_input().strip().split()]
        f[l][r] += 1
    for d in xrange(1, n):
        for i in xrange(0, n - d):
            f[i][i + d] += f[i][i + d - 1] + f[i + 1][i + d] - f[i + 1][i + d - 1]
    for i in xrange(q):
        p, q = [int(i) - 1 for i in raw_input().strip().split()]
        print f[p][q]

if __name__ == '__main__':
    main()
