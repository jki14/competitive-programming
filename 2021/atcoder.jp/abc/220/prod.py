from sys import stdout


def solution(a):
    n = len(a)
    m = 998244353
    f = [[0 for j in xrange(10)] for i in xrange(n)]
    f[0][a[0]] = 1
    for i in xrange(n - 1):
        for j in xrange(10):
            k = (j + a[i + 1]) % 10
            f[i + 1][k] = (f[i + 1][k] + f[i][j]) % m
            k = (j * a[i + 1]) % 10
            f[i + 1][k] = (f[i + 1][k] + f[i][j]) % m
    stdout.write('\n'.join([str(i) for i in f[n - 1]]) + '\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            a = [int(i) for i in raw_input().strip().split()]
            solution(a)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
