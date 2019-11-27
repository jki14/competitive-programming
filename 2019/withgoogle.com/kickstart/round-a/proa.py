import sys

def solution(n, m, a):
    a = sorted(a)
    b = [0 for i in xrange(n + 1)]
    for i in xrange(n):
        b[i + 1] = b[i] + a[i]
    foo = a[n - 1] * m
    for i in xrange(m, n + 1):
        foo = min(a[i - 1] * m - b[i] + b[i - m], foo)
    return foo

def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n, m = [int(j) for j in raw_input().strip().split()]
        a = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %d\n' % (i + 1, solution(n, m, a)))

if __name__ == '__main__':
    main()
