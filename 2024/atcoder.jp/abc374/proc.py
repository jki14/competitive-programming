from sys import stdout


def solution(a):
    n = len(a)
    res = sum(a)
    for s in range(1 << n):
        foo, bar = 0, 0
        for i in range(n):
            if ((s >> i) & 1) == 1:
                foo += a[i]
            else:
                bar += a[i]
        res = min(max(foo, bar), res)
    stdout.write("%d\n" % res)


def main():
    while True:
        try:
            n = int(input().strip())
            a = [int(i) for i in input().strip().split()]
        except ValueError:
            continue
        except EOFError:
            break
        solution(a)


if __name__ == '__main__':
    main()
