import sys

def solution(n, m, a):
    a = sorted(a)
    foo, bar = 0, 0
    while foo < n and bar + a[foo] <= m:
        bar += a[foo]
        foo += 1
    return foo

def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n, m = [int(j) for j in raw_input().strip().split()]
        a = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %d\n' % (i + 1, solution(n, m, a)))

if __name__ == '__main__':
    main()
