from sys import stdout


def solution(x):
    stdout.write('Yes\n' if x > 0 and x % 100 == 0 else 'No\n')


def main():
    while True:
        try:
            x = int(raw_input().strip())
            solution(x)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
