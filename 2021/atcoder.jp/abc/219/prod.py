from sys import stdout, stderr


def solution(a, x, y):
    inf = 0x3f3f3f3f

    n = len(a)
    f = [[inf for k in xrange(y + 1)] for j in xrange(x + 1)]
    f[0][0] = 0

    for i in xrange(n):
        g = f
        f = [[inf for k in xrange(y + 1)] for j in xrange(x + 1)]
        for j in xrange(x + 1):
            for k in xrange(y + 1):
                if g[j][k] >= inf:
                    continue
                f[j][k] = min(g[j][k], f[j][k])
                p = min(j + a[i][0], x)
                q = min(k + a[i][1], y)
                f[p][q] = min(g[j][k] + 1, f[p][q])
 
    stdout.write(str(f[x][y] if f[x][y] < inf else -1) + '\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            x, y = [int(i) for i in raw_input().strip().split()]
            a = [tuple([int(j) for j in raw_input().strip().split()]) for i in xrange(n)]
            solution(a, x, y)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
