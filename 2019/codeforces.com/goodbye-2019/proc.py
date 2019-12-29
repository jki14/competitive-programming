import sys

def solution(a, n):
    s = sum(a)
    p = 1
    while p <= s:
        p <<= 1
    p <<= 1
    if (s & 1) == 1:
        p |= 1
    xor = p
    for d in a:
        xor ^= d
    xor <<= 1
    x = (xor - s - p) >> 1
    return (p, x, x)
    

def main():
    case_num = int(input())
    for k in range(case_num):
        n = int(input())
        a = [int(i) for i in input().strip().split()]
        foo = solution(a, n)
        sys.stdout.write('%d\n' % len(foo))
        sys.stdout.write('%s\n' % ' '.join([str(i) for i in foo]))

if __name__ == '__main__':
    main()
