from fractions import gcd
from sys import stderr, stdout


def cook(s):
    return int(s.replace('T', '1').replace('F', '0'), 2)


def popcount(x):
    return bin(x).count('1')


def check(a, k, m):
    for c in a:
        if popcount(k ^ c[0]) != m - c[1]:
            return False
    return True


def solution():
    n, m = [int(i) for i in raw_input().strip().split()]
    b = [[j for j in raw_input().strip().split()] for i in xrange(n)]
    a = [(cook(b[i][0]), int(b[i][1])) for i in xrange(n)]
    foo = []
    for k in xrange(2 ** m):
        if check(a, k, m):
            foo.append(k)
    w, x, y = 0, 0, len(foo)
    for r in xrange(2 ** m):
        s = sum([m - popcount(r ^ k) for k in foo])
        if s > x:
            x = s
            w = r
    w = bin(w)[2:].replace('0', 'F').replace('1', 'T')
    w = 'F' * (m - len(w)) + w
    if x > 0 and y > 0:
        z = gcd(x, y)
        x /= z
        y /= z
    stdout.write('%s %d/%d\n' % (w, x, y))


def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        stdout.write('Case #%d: ' % (i + 1))
        solution()


if __name__ == '__main__':
    main()
