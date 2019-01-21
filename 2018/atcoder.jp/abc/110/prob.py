def solution(a, b):
    if max(a) < min(b):
        return 'No War'
    else:
        return 'War'

def main():
    n, m, x, y = [int(i) for i in raw_input().strip().split()]
    a = [x] + [int(i) for i in raw_input().strip().split()]
    b = [y] + [int(i) for i in raw_input().strip().split()]
    print(solution(a, b))

if __name__ == '__main__':
    main()
