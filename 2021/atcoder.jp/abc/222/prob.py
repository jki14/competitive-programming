from sys import stdout


def solution(a, p):
    stdout.write(str(sum([1 if v < p else 0 for v in a])) + '\n')


def main():
    while True:
        try:
            n, p = [int(i) for i in raw_input().strip().split()]
            a = [int(i) for i in raw_input().strip().split()]
            solution(a, p)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
