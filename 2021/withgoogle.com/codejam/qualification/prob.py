from sys import stderr, stdout


def solution(a, x, y):
    inf = 0x3f3f3f3f
    # constexpr
    n = len(a)
    f = [[inf for j in xrange(2)] for i in xrange(n)]
    if a[0] != 'J':
        f[0][0] = 0
    if a[0] != 'C':
        f[0][1] = 0
    for i in xrange(1, n):
        if a[i] != 'J':
            f[i][0] = min(f[i - 1][0], f[i][0])
            f[i][0] = min(f[i - 1][1] + y, f[i][0])
        if a[i] != 'C':
            f[i][1] = min(f[i - 1][1], f[i][1])
            f[i][1] = min(f[i - 1][0] + x, f[i][1])
    stdout.write('%d\n' % min(f[n - 1][0], f[n - 1][1]))


def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        stdout.write('Case #%d: ' % (i + 1))
        x, y, a = raw_input().strip().split()
        x, y = int(x), int(y)
        solution(a, x, y)


if __name__ == '__main__':
    main()
