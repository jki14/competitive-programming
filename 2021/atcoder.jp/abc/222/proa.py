from sys import stdout


def solution(n):
    s = str(n)
    s = '0' * (4 - len(s)) + s
    stdout.write(s + '\n')


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
