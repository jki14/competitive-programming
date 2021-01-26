import sys


def solution(a, d):
    for k in a[::-1]:
        d -= d % k
    return d


def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n, d = [int(j) for j in raw_input().strip().split()]
        a = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %d\n' % (i + 1, solution(a, d)))


if __name__ == '__main__':
    main()
