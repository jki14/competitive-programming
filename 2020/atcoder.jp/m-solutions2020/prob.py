import sys


def handler():
    a, b, c = [int(i) for i in input().strip().split()]
    bar = int(input().strip())
    foo = 0
    while b <= a:
        b *= 2
        foo += 1
    while c <= b:
        c *= 2
        foo += 1
    if foo <= bar:
        sys.stdout.write('Yes\n')
    else:
        sys.stdout.write('No\n')


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
