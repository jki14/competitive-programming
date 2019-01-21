def process(a, b):
    if a > 8 or b > 8:
        return ':('
    else:
        return 'Yay!'

def main():
    a, b = [int(i) for i in raw_input().strip().split()]
    print process(a, b)

if __name__ == '__main__':
    main()
