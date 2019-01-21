def solution(k):
    return (k >> 1) * ((k + 1) >> 1)

def main():
    k = int(raw_input().strip())
    print solution(k)

if __name__ == '__main__':
    main()
