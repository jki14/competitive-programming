import numpy as np
import sys

def CatchThemAll(n, p, edges):
    g = np.array([[1e9 for i in xrange(n)] for j in xrange(n)])
    for i in xrange(n):
        g[i][i] = 0.0
    for u, v, w in edges:
        g[u - 1][v - 1] = min(w * 1.0, g[u - 1][v - 1])
        g[v - 1][u - 1] = min(w * 1.0, g[v - 1][u - 1])
    for x in xrange(n):
        for u in xrange(n):
            for v in xrange(n):
                g[u][v] = min(g[u][x] + g[x][v], g[u][v])
    tmp = np.sum(g, axis = 1)
    o2p = tmp[0] / (n - 1)
    p2a = np.sum(tmp[1:]) / (n - 1) / (n - 1)
    # print('o2p = %.6f, p2a = %.6f' % (o2p, p2a))
    lhs = np.array([[0., 1., 0.], [0., 0., 0.], [0., 0., 0.]])
    rhs = np.array([[1., o2p, p2a], [0., 0., 1./(n - 1)], [0., 1., (n - 2)*1./(n - 1)]]).T
    return np.matmul(lhs, np.linalg.matrix_power(rhs, p))[0][0]

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        n, m, p = [int(j) for j in raw_input().strip().split()]
        edges = [[int(k) for k in raw_input().strip().split()] for j in xrange(m)]
        print('Case #%d: %.13f' % (i + 1, CatchThemAll(n, p, edges)))
        sys.stdout.flush()

if __name__ == '__main__':
    main()
