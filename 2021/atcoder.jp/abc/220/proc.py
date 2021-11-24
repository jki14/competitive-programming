from sys import stdout


def solution(a, x):
    n = len(a)
    s = sum(a)
    foo = x // s * n
    x %= s
    bar = 0
    while x >= 0:
        x -= a[bar]
        bar += 1
    stdout.write('%d\n' % (foo + bar))


def main():
    while True:
        try:
            n = int(raw_input().strip())
            a = [int(i) for i in raw_input().strip().split()]
            x = int(raw_input().strip())
            solution(a, x)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
