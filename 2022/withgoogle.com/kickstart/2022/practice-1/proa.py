from sys import stdout


def handler():
    n, m = [int(i) for i in input().strip().split()]
    c = [int(i) for i in input().strip().split()]
    stdout.write('%d\n' % (sum(c) % m))


def main():
    t = int(input().strip())
    for i in range(t):
        stdout.write('Case #%d: ' % (i + 1))
        handler()


if __name__ == '__main__':
    main()
