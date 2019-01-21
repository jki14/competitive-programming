def solution(a):
    a = [a[i] - i - 1 for i in xrange(len(a))]
    a = sorted(a)
    b = a[len(a) >> 1]
    return sum([abs(i - b) for i in a])

def main():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    print solution(a)

if __name__ == '__main__':
    main()