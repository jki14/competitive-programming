from math import floor
from sys import stderr, stdout


def solution(s):
    p = s.find('.')
    if p == -1:
        p = len(s)
    stdout.write('%d\n' % int(s[:p]))


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
