import numpy as np
from sys import stdout

def MatrixModPow(a, k, mod = 1000000007):
    foo = np.eye(a.shape[0], a.shape[1], dtype = np.int64)
    cur = a
    rank = 1
    while rank <= k:
        if (rank & k) != 0:
            foo = np.matmul(foo, cur)
            foo = np.remainder(foo, mod)
        cur = np.matmul(cur, cur)
        cur = np.remainder(cur, mod)
        rank <<= 1
    return foo

def KickstartAlarm(a, k, mod = 1000000007):
    n = len(a)
    foo = 0
    prefix = 0
    for i in xrange(n):
        lhs = np.array([[0, i + 1], [0, 0]], dtype = np.int64)
        rhs = np.array([[1, 1], [0, i + 1]], dtype = np.int64).T
        increment = np.matmul(lhs, MatrixModPow(rhs, k))[0][0] % mod
        prefix = (prefix + increment) % mod
        foo = (foo + prefix * a[i] % mod * (n - i) % mod) % mod
    foo = (foo % mod + mod) % mod
    return foo

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        n, k, x1, y1, C, D, E1, E2, F = [int(j) for j in raw_input().strip().split()]
        x = [x1 for j in xrange(n)]
        y = [y1 for j in xrange(n)]
        for j in xrange(1, n):
            x[j] = (x[j - 1] * C + y[j - 1] * D + E1) % F
            y[j] = (x[j - 1] * D + y[j - 1] * C + E2) % F
        a = [(x[j] + y[j]) % F for j in xrange(n)]
        print('Case #%d: %d' % (i + 1, KickstartAlarm(a, k)))
        stdout.flush()

if __name__ == '__main__':
    main()
