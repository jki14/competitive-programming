def divisors_num(x):
    foo = 0
    p = 1
    while p * p <= x:
        if x % p == 0:
            q = x / p
            if p != q:
                foo += 2
            else:
                foo += 1
        p += 1
    return foo

def main():
    n = int(raw_input().strip())
    foo = 0
    for k in xrange(1, n + 1, 2):
        if divisors_num(k) == 8:
            foo += 1
    print foo

if __name__ == '__main__':
    main()
