from sys import stdout


def solution(a, b, c):
    foo = (a - 1) // c * c + c
    stdout.write('%d\n' % (foo if foo <= b else -1))


def main():
    while True:
        try:
            a, b, c = [int(i) for i in raw_input().strip().split()]
            solution(a, b, c)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
