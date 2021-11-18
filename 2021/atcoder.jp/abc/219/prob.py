from sys import stdout


def solution(s, t):
    stdout.write(''.join(s[i - 1] for i in t) + '\n')


def main():
    while True:
        try:
            s = [raw_input().strip() for i in xrange(3)]
            t = [int(i) for i in raw_input().strip()]
            solution(s, t)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
