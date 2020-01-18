import sys

def main():
    n, k, s = [int(i) for i in raw_input().strip().split()]
    if k == 0:
        foo = [s + 1 if s < 1000000000 else 999999999] * n
    elif s > (n - k):
        foo = [1] * (n - k) + [s - (n - k)] + [s] * (k - 1)
    else:
        foo = [s] * k + [n] * (n - k)
    foo = [str(i) for i in foo]
    sys.stdout.write('%s\n' % ' '.join(foo))

if __name__ == '__main__':
    main()
