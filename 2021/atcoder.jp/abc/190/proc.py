import sys


def solution(n, r, s):
    foo = 0
    for k in xrange(1 << len(s)):
        a = [False for i in xrange(n)]
        for i in xrange(len(s)):
            a[s[i][(k >> i) & 1]] = True
        bar = 0
        for c in r:
            if a[c[0]] and a[c[1]]:
                bar += 1
        foo = max(foo, bar)
    sys.stdout.write('%d\n' % foo)


def main():
    while True:
        try:
            n, m = [int(i) for i in raw_input().strip().split()]
            r = [tuple(int(j) - 1 for j in raw_input().strip().split())
                    for i in xrange(m)]
            k = int(raw_input().strip())
            s = [tuple(int(j) - 1 for j in raw_input().strip().split())
                    for i in xrange(k)]
            solution(n, r, s)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
