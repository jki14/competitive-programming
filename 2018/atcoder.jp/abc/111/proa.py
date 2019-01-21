def solution(x, y):
    return max(x + y, max(x - y, x * y))

def main():
    x, y = [int(i) for i in raw_input().strip().split()]
    print solution(x, y)

if __name__ == '__main__':
    main()
