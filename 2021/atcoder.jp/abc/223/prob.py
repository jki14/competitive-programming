from sys import stdout


def solution(s):
    n = len(s)
    a = sorted([s[i:] + s[:i] for i in xrange(n)])
    stdout.write('%s\n%s\n' % (a[0], a[-1]))


def main():
    while True:
        try:
            s = raw_input().strip()
            solution(s)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
