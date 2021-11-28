from sys import stdout


def solution(n):
    res = 0
    s = str(n)
    l = len(s)
    # stdout.write('l = ' + str(l) + '\n')
    for c in xrange(1, 2 ** l - 1):
        # stdout.write('c = ' + str(c) + '\n')
        lhs = ''
        rhs = ''
        for i in xrange(l):
            if ((c >> i) & 1) > 0:
                lhs += s[i]
            else:
                rhs += s[i]
        lhs = ''.join(sorted(lhs, reverse=True))
        rhs = ''.join(sorted(rhs, reverse=True))
        # stdout.write('lhs = %s, rhs = %s\n' % (lhs, rhs))
        res = max(int(lhs) * int(rhs), res)
    stdout.write(str(res) + '\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            solution(n)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
