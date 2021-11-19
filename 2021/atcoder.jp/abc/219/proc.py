from sys import stdout


def solution(s, x):
    x2c = dict(zip([chr(ord('a') + i) for i in xrange(26)], x))
    c2x = dict((v,k) for k, v in x2c.iteritems())

    n = len(s)
    s = sorted([''.join([c2x[c] for c in s[i]]) for i in xrange(n)])
    stdout.write('\n'.join([''.join([x2c[c] for c in s[i]]) for i in xrange(n)]) + '\n')


def main():
    while True:
        try:
            x = raw_input().strip()
            n = int(raw_input().strip())
            s = [raw_input().strip() for i in xrange(n)]
            solution(s, x)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
