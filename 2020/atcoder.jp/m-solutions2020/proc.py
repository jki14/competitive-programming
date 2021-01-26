import sys


def handler():
    n, m = [int(i) for i in input().strip().split()]
    a = [int(i) for i in input().strip().split()]
    for i in range(m, n):
        if a[i] <= a[i - m]:
            sys.stdout.write('No\n')
        else:
            sys.stdout.write('Yes\n')


def main():
    while True:
        try:
            handler()
        except ValueError:
            continue
        except EOFError:
            break


if __name__ == '__main__':
    main()
