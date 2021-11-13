from sys import stdout


def solution(s, n):
    stdout.write('Yes\n' if s[n - 1] == 'o' else 'No\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            s = raw_input().strip()
            solution(s, n)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
