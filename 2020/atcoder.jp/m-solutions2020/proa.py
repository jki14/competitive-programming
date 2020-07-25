import sys


def handler():
    x = int(input().strip())
    sys.stdout.write('%d\n' % (10 - x // 200))


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
