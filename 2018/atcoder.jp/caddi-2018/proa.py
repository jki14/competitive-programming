def process(n, p):
    foo = 1
    k = 2
    while k * k <= p:
        c = 0
        while p % k == 0:
            p /= k
            c += 1
        if c >= n:
            foo *= k ** (c / n)
        k += 1
    if n == 1:
        foo *= p
    return foo

def main():
    n, p = [int(i) for i in raw_input().strip().split()]
    print process(n, p)

if __name__ == '__main__':
    main()
