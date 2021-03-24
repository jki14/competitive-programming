from sys import stdout


def solution(a, b, c, d):
    stdout.write('%d\n' % (b - c))


def main():
    while True:
        try:
            a, b = [int(i) for i in raw_input().strip().split()]
            c, d = [int(i) for i in raw_input().strip().split()]
            solution(a, b, c, d)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
