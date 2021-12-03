from sys import stdout


def solution(a, b):
    msk = 998244353
    n = len(a)
    f = [[0 for j in xrange(b[-1] + 1)] for i in xrange(n + 1)]
    f[0][0] = 1
    for i in xrange(n):
        subsum = 0
        for k in xrange(b[i] + 1):
            subsum = (subsum + f[i][k]) % msk
            if k >= a[i]:
                f[i + 1][k] = (f[i + 1][k] + subsum) % msk
    stdout.write(str(sum(f[n]) % msk) + '\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            a = [int(i) for i in raw_input().strip().split()]
            b = [int(i) for i in raw_input().strip().split()]
            solution(a, b)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
