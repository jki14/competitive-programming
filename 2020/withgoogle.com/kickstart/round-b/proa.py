import sys


def solution(a, n):
    return sum([1 if a[i] > a[i - 1] and a[i] > a[i + 1] else 0 for i in xrange(1, n -1)])


def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n = int(raw_input().strip())
        a = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %d\n' % (i + 1, solution(a, n)))


if __name__ == '__main__':
    main()
