from sys import stdout


def solution(n):
    foo = 0
    while n > 1:
        n >>= 1
        foo += 1
    stdout.write('%d\n' % foo)


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
