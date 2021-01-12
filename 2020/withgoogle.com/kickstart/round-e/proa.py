import sys


def solution(a):
    d = [a[i] - a[i - 1] for i in xrange(1, len(a))]
    b = [1 if d[i] == d[i - 1] else 0 for i in xrange(1, len(d))]
    c = [-1,] + [i for i in xrange(len(b)) if b[i] == 0] + [len(b),]
    return max([c[i] - c[i - 1] for i in xrange(1, len(c))]) + 1


def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n = int(raw_input().strip())
        a = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %d\n' % (i + 1, solution(a)))


if __name__ == '__main__':
    main()
