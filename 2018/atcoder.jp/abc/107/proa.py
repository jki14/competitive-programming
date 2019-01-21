def solution(x, y):
    return x - y + 1

def main():
    x, y = [int(i) for i in raw_input().strip().split()]
    print solution(x, y)

if __name__ == '__main__':
    main()
