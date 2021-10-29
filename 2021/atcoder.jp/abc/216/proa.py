from sys import stdout


def solution(s):
    pd = s.index('.')
    x, y = int(s[:pd]), int(s[pd + 1:])
    stdout.write(str(x) + ('-' if y <= 2 else ('+' if y >= 7 else '')) + '\n')


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
