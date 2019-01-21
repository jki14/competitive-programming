from operator import itemgetter

def solution(a):
    n = len(a)
    lhs, rhs = {-1 : 0}, {-1 : 0}
    for i in xrange(0, n, 2):
        if a[i] not in lhs:
            lhs[a[i]] = 0
        lhs[a[i]] += 1
    for i in xrange(1, n ,2):
        if a[i] not in rhs:
            rhs[a[i]] = 0
        rhs[a[i]] += 1
    lhs = sorted(lhs.items(), key = itemgetter(1), reverse = True)
    rhs = sorted(rhs.items(), key = itemgetter(1), reverse = True)
    if lhs[0][0] != rhs[0][0]:
        return n - lhs[0][1] - rhs[0][1]
    else:
        return min(n - lhs[0][1] - rhs[1][1], n - lhs[1][1] - rhs[0][1])

def main():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    print solution(a)

if __name__ == '__main__':
    main()
