import sys

inf = 2 ** 30

def solution(a):
    n = len(a)
    m = ((n + 1) >> 1) - sum([v & 1 for v in a])
    f = [[[inf for k in range(2)] for j in range(m +1)] for i in range(n + 1)]
    f[0][0][0], f[0][0][1] = 0, 0
    for i in range(n):
        for j in range(min(m, i) + 1):
            for k in range(2):
                #sys.stderr.write('f[%d][%d][%d] = %d\n' % (i, j, k, f[i][j][k]));
                # fixed
                if a[i] != 0:
                    t = a[i] & 1 
                    w = 1 if t != k else 0
                    f[i + 1][j][t] = min(f[i][j][k] + w, f[i + 1][j][t])
                    continue
                # +1
                if j < m:
                    w = 1 if k != 1 else 0
                    f[i + 1][j + 1][1] = min(f[i][j][k] + w, f[i + 1][j + 1][1])
                # +0
                w = 1 if k != 0 else 0
                f[i + 1][j][0] = min(f[i][j][k] + w, f[i + 1][j][0])
    return min(f[n][m][0], f[n][m][1])

def main():
    while True:
        try:
            n = int(input().strip())
            a = [int(i) for i in input().strip().split()]
            sys.stdout.write('%d\n' % solution(a))
        except ValueError:
            continue
        except EOFError:
            break

if __name__ == '__main__':
    main()
