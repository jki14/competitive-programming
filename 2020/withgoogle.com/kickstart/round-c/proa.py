import sys


def solution(a, m):
    foo, bar = 0, m
    for e in a:
        if bar == e:
            bar -= 1
            if bar == 0:
                foo += 1
            else:
                continue
        elif m == e:
            bar = m - 1
            continue
        bar = m
    return foo


def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n, m = [int(j) for j in raw_input().strip().split()]
        a = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %d\n' % (i + 1, solution(a, m)))


if __name__ == '__main__':
    main()
