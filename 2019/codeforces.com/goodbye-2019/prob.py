import sys

def solution(a, n):
    p = 0
    for i in range(1, n):
        if i + a[i] + 1 <= p + a[p]:
            return (p + 1, i + 1)
        if p + a[p] < i + a[i]:
            p = i
    p = 0
    for i in range(1, n):
        if i - a[i] + 1 <= p - a[p]:
            return (p + 1, i + 1)
        if p - a[p] < i - a[i]:
            p = i
    return None

def main():
    case_num = int(input())
    for k in range(case_num):
        n = int(input())
        a = [int(i) for i in input().strip().split()]
        foo = solution(a, n)
        if foo:
            sys.stdout.write('YES\n%d %d\n' % foo)
        else:
            sys.stdout.write('NO\n')

if __name__ == '__main__':
    main()
