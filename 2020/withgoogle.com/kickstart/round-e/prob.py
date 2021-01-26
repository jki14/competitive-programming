import sys


def solution(n, a, b, c):
    foo = [n - 1,] * (a - c) + [n,] * c + [n - 1,] * (b - c)
    if len(foo) > n:
        return 'IMPOSSIBLE'
    idx = foo.index(n)
    if idx != len(foo) - 1:
        foo = foo[:idx + 1] + [1] * (n - len(foo)) + foo[idx + 1:]
    else:
        foo = foo[:idx] + [1] * (n - len(foo)) + foo[idx:]
    lhs = [1 if i == 0 or max(foo[:i]) <= foo[i] else 0 for i in xrange(n)]
    rhs = [1 if i == n - 1 or max(foo[i + 1:]) <= foo[i] else 0 for i in xrange(n)]
    bar = [lhs[i] & rhs[i] for i in xrange(n)]
    if sum(lhs) != a or sum(rhs) != b or sum(bar) != c:
        return 'IMPOSSIBLE'
    return ' '.join([str(i) for i in foo])


def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n, a, b, c = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %s\n' % (i + 1, solution(n, a, b, c)))


if __name__ == '__main__':
    main()
