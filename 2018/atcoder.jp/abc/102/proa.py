def solution(x):
    if (x & 1) == 0:
        return x
    else:
        return x << 1

def main():
    n = int(raw_input().strip())
    print solution(n)

if __name__ == '__main__':
    main()