import os

def main():
    n, m, k = [int(i) for i in raw_input().strip().split()]
    a = [int(i) for i in raw_input().strip().split()]
    p = [int(i) for i in raw_input().strip().split()]
    b = [a[i] + (int(os.urandom(4).encode('hex'), 16) % k) for i in xrange(n)]
    print ' '.join(str(i) for i in b)

if __name__ == '__main__':
    main()
