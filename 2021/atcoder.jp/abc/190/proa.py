import sys


def solution(a, b, c):
    if c == 1:
        a, b = a + 0.5, b
    if a > 0 and a > b:
        sys.stdout.write('Takahashi\n')
    else:
        sys.stdout.write('Aoki\n')


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
