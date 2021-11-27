from sys import stdout


def solution(s, t):
    if s == t:
        stdout.write('Yes\n')
        return
    n = len(s)
    for i in xrange(n - 1):
        if s[:i] + s[i + 1] + s[i] + s[i + 2:] == t:
            stdout.write('Yes\n')
            return
    stdout.write('No\n')


def main():
    while True:
        try:
            s = raw_input().strip()
            t = raw_input().strip()
            solution(s, t)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
