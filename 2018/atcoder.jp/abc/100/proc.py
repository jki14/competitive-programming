def solution(a):
    cnt = 0
    for x in a:
        while (x & 1) == 0:
            x >>= 1
            cnt += 1
    return cnt

def main():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    print solution(a)

if __name__ == '__main__':
    main()
