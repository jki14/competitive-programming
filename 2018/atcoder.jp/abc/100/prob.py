def process(d, n):
    if n < 100:
        return n * (100 ** d)
    else:
        return 101 * (100 ** d)

def main():
    d, n = [int(i) for i in raw_input().strip().split()]
    print process(d, n)

if __name__ == '__main__':
    main()
