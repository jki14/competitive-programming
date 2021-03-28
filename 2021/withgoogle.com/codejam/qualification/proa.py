from sys import stdout


def solution(a):
    n = len(a)
    foo = 0
    for i in xrange(n - 1):
        pos = a.index(i + 1)
        foo += pos - i + 1
        if i > 0:
            a = a[:i] + a[pos: i - 1: -1] + a[pos + 1:]
        else:
            a = a[pos::-1] + a[pos + 1:]
    stdout.write('%d\n' % foo)


def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        stdout.write('Case #%d: ' % (i + 1))
        n = int(raw_input().strip())
        a = [int(j) for j in raw_input().strip().split()]
        assert(len(a) == n)
        solution(a)


if __name__ == '__main__':
    main()
