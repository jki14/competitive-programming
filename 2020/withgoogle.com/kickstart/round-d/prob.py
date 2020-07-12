import sys

def solution(n, a):
    foo, low, hig = 0, 0, 0
    for i in xrange(1, n):
        if a[i] > a[i - 1]:
            hig = hig + 1
            low = 0
        elif a[i] < a[i - 1]:
            low = low + 1
            hig = 0
        if hig > 3 or low > 3:
            foo += 1
            low, hig = 0, 0
    return foo

def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        n = int(raw_input().strip())
        a = [int(j) for j in raw_input().strip().split()]
        sys.stdout.write('Case #%d: %d\n' % (i + 1, solution(n, a)))

if __name__ == '__main__':
    main()
