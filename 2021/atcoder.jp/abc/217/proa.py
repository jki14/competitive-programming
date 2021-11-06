from sys import stdout


def solution(s, t):
    stdout.write('Yes\n' if s < t else 'No\n')


def main():
    while True:
        try:
            s, t = [i for i in raw_input().strip().split()]
            solution(s, t)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
