import sys


def handler():
    l, r, d = [int(i) for i in input().strip().split()]
    sys.stdout.write('%d\n' % (r // d - (l - 1) // d))


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
