import sys


def solution(a, s, d):
    for spell in a:
        if spell[0] < s and spell[1] > d:
            sys.stdout.write('Yes\n')
            return
    sys.stdout.write('No\n')


def main():
    while True:
        try:
            n, s, d = [int(i) for i in raw_input().strip().split()]
            a = [tuple(int(j) for j in raw_input().strip().split())
                    for i in xrange(n)]
            solution(a, s, d)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
