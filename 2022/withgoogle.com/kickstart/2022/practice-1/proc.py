from sys import stdout


C = 100000


def lowbit(i):
    return i & -i


def add(i, b):
    while i <= C:
        b[i] += 1
        i += lowbit(i)


def qry(i, b):
    bar = 0
    while i > 0:
        bar += b[i]
        i -= lowbit(i)
    return bar


def handler():
    n = int(input().strip())
    a = [int(i) for i in input().strip().split()]
    b = [0 for i in range(C + 1)]
    bar = 1
    for i in range(n):
        add(a[i], b)
        while bar < C and i + 1 - qry(bar, b) > bar:
            bar += 1
        stdout.write(' %d' % bar)
    stdout.write('\n')


def main():
    t = int(input().strip())
    for i in range(t):
        stdout.write('Case #%d: ' % (i + 1))
        handler()


if __name__ == '__main__':
    main()
