from sys import stdout


def solution(n):
    bar = [4 for i in range(125)] + [6 for i in range(125, 211)] + [8 for i in range(211, 214)]
    stdout.write('%d\n' % (bar[n - 1]))


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
