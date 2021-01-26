def main():
    n, x = [int(i) for i in raw_input().strip().split()]
    a = [tuple([int(j) for j in raw_input().strip().split()]) for i in xrange(n)]
    x = x * 100
    for i in xrange(n):
        x -= a[i][0] * a[i][1]
        if x < 0:
            print(i + 1)
            return
    print('-1')


if __name__ == '__main__':
    main()
