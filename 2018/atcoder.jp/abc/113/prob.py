def solution(h, t, a):
    n = len(h)
    foo, goo = -1, 0
    for i in range(n):
        cur = abs(t * 1000- h[i] * 6 - a * 1000)
        if foo == -1 or goo > cur:
            goo = cur
            foo = i
    return foo

def main():
    n = int(input().strip())
    t, a = [int(i) for i in input().strip().split()]
    h = [int(i) for i in input().strip().split()]
    print(solution(h, t, a) + 1)

if __name__ == '__main__':
    main()
