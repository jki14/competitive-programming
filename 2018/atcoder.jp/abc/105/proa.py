def main():
    n, k = [int(i) for i in raw_input().strip().split()]
    if n % k == 0:
        print 0
    else:
        print 1

if __name__ == '__main__':
    main()
