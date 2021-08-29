from sys import stdout

def build(a):
    prev = 0
    for curr in sorted(a.keys())[1:]:
        a[curr] = a[prev] + curr - prev - 1
        prev = curr
    return a


def solution(a, h, w):
    n = len(a)

    r = {0: 0}
    for i in xrange(n):
        r[a[i][0]] = 0
    r = build(r)

    c = {0: 0}
    for i in xrange(n):
        c[a[i][1]] = 0
    c = build(c)

    for i in xrange(n):
        stdout.write('%d %d\n' % (a[i][0] - r[a[i][0]], a[i][1] - c[a[i][1]]))


def main():
    while True:
        try:
            h, w, n = [int(i) for i in raw_input().strip().split()]
            a = [tuple([int(j) for j in raw_input().strip().split()]) for i in xrange(n)]
            solution(a, h, w)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
