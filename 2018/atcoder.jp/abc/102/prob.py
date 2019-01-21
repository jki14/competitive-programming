def solution(a):
    return max(a) - min(a)

def main():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    print solution(a)

if __name__ == '__main__':
    main()