def process(x, y):
    return x + (y >> 1)

def main():
    x, y = [int(i) for i in raw_input().strip().split()]
    print(process(x, y))

if __name__ == '__main__':
    main()
