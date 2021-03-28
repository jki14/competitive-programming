from sys import stderr, stdout


def solution(n, c):
    if c < n or c > (1 + n) * n / 2:
        stdout.write('IMPOSSIBLE\n')
        return
    a = [i for i in xrange(n)] 
    c -= n
    for i in xrange(n - 2, -1, -1):
        if c > 0:
            k = min(n - i - 1, c)
            c -= k
            pos = i + k
            if i > 0:
                a = a[:i] + a[pos: i - 1: -1] + a[pos + 1:]
            else:
                a = a[pos::-1] + a[pos + 1:]
        else:
            break
    assert(c == 0)
    foo = ' '.join([str(i + 1) for i in a])
    stdout.write('%s\n' % foo)


def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        stdout.write('Case #%d: ' % (i + 1))
        n, c = [int(j) for j in raw_input().strip().split()]
        solution(n, c + 1)


if __name__ == '__main__':
    main()
