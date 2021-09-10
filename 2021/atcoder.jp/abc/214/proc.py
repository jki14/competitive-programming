from sys import stdout


def solution(s, t):
    inf = 0x3f3f3f3f
    n = len(s)
    f = [inf for i in xrange(n)]
    for k in xrange(2):
        for i in xrange(n):
            f[i] = min(t[i], f[i])
            f[i] = min(f[i - 1] + s[i - 1], f[i])
    stdout.write('%s\n' % '\n'.join([str(i) for i in f]))


def main():
    while True:
        try:
            n = int(raw_input().strip())
            s = [int(i) for i in raw_input().strip().split()]
            t = [int(i) for i in raw_input().strip().split()]
            solution(s, t)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
