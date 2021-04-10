from sys import stderr, stdout


def greater(foo, bar):
    n, m = len(foo), len(bar)
    if n > m:
        return foo, 0
    r = m - n
    for i in xrange(n):
        if foo[i] > bar[i]:
            foo = foo + ['0'] * r
            return foo, r
        elif foo[i] < bar[i]:
            foo = foo + ['0'] * (r + 1)
            return foo, r + 1
    if r == 0:
        foo = foo + ['0']
        return foo, 1
    elif bar[-r:].count('9') == r:
        foo = foo + ['0'] * (r + 1)
        return foo, r + 1
    else:
        foo = bar
        for i in xrange(m - 1, n - 1, -1):
            if foo[i] != '9':
                foo[i] = chr(ord(foo[i]) + 1)
                for j in xrange(i + 1, m):
                    foo[j] = '0'
                return foo, r


def solution():
    n = int(raw_input().strip())
    a = [list(i) for i in raw_input().strip().split()]
    foo = 0
    for i in xrange(1, n):
        a[i], bar = greater(a[i], a[i - 1])
        foo += bar
    # stderr.write('%s\n' % str(a))
    stdout.write('%d\n' % foo)


def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        stdout.write('Case #%d: ' % (i + 1))
        solution()


if __name__ == '__main__':
    main()
