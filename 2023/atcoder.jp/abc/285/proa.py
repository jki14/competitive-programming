from sys import stdout


def solution(a, b):
    if a * 2 == b or a * 2 + 1 == b:
        stdout.write('Yes\n')
    else:
        stdout.write('No\n')


def main():
    while True:
        try:
            a, b = [int(i) for i in input().strip().split()]
        except ValueError:
            continue
        except EOFError:
            break
        solution(a, b)


if __name__ == '__main__':
    main()
