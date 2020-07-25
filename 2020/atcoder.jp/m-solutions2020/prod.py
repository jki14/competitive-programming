import sys


def handler():
    n = int(input().strip())
    a = [int(i) for i in input().strip().split()]
    cash, stock = 1000, 0
    buyin = 0
    for i in range(n):
        if stock > 0:
            # sys.stderr.write('[%d] sold %d (buyin = %d)\n' % (i, stock, buyin))
            cash += stock * max(buyin, a[i])
            stock = 0
        if i < n - 1 and cash >= a[i] and a[i] <= max(a[i + 1:]):
            buyin = a[i]
            k = cash // a[i]
            cash -= k * a[i]
            stock += k
            # sys.stderr.write('[%d] buy %d\n' % (i, k))
        # sys.stderr.write('%d, %d\n' % (cash, stock))
    sys.stdout.write('%d\n' % cash)


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
