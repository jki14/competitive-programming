import sys

def solution(n, a):
    foo, bar = 0, -1
    for i in xrange(n):
        if a[i] > bar and (i == n - 1 or a[i] > a[i + 1]):
            foo += 1
        bar = max(bar, a[i])
    return foo

def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n = int(raw_input().strip())
        a = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %d\n' % (i + 1, solution(n, a)))

if __name__ == '__main__':
    main()
