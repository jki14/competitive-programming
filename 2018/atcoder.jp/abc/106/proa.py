def solution(a, b):
    return a * b - (a + b - 1)

def main():
    a, b = [int(i) for i in raw_input().strip().split()]
    print solution(a, b)

if __name__ == '__main__':
    main()
