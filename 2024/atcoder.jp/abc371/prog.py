from math import gcd, log2
from sys import stderr, stdout


def solution(n, p, a):
    p = [p[i] - 1 for i in range(n)]

    v = [False for i in range(n)]
    s = [0 for i in range(n)]
    gd, gm = 0, 1
    for i in range(n):
        m = 0
        j = i
        while not v[j]:
            v[j] = True
            s[m] = a[j]
            m += 1
            j = p[j]
        # stderr.write('..m = ' + str(m) + '\n')
        if m > 1:
            b = [False for i in range(m)]
            j = gd % m
            while not b[j]:
                b[j] = True
                j = (j + gm) % m
            d = min([(s[k] if b[k] else n + 1, k) for k in range(m)])[1]
            j = i
            for k in s[d : m] + s[0 : d]:
                a[j] = k
                j = p[j]
            while gd % m != d:
                gd += gm
            gm = gm // gcd(m, gm) * m
    # stderr.write('gd = ' + str(gd) + '\n')
    # stderr.write('gm = ' + str(gm) + '\n')
    # stderr.write('log2(gd) = %.2f\n' % log2(gd))
    # stderr.write('log2(gm) = %.2f\n' % log2(gm))
    stdout.write(' '.join([str(i) for i in a]))
    stdout.write('\n')


def main():
    while True:
        try:
            n = int(input().strip())
        except EOFError:
            break
        p = [int(i) for i in input().strip().split()]
        a = [int(i) for i in input().strip().split()]
        while len(p) != n:
            pass
        while len(a) != n:
            pass
        solution(n, p, a)


if __name__ == '__main__':
    main()
