def solution(a, k):
    n = len(a)
    p, q = [0], []
    for x in a:
        if x < 0:
            q.append(-x)
        else:
            p.append(x)
    q = [0] + q[::-1]
    foo = min(p[-1], q[-1]) * 2 + max(p[-1], q[-1])
    for x in xrange(max(0, k - len(p) + 1), min(k, len(q) - 1) + 1):
        y = k - x
        foo = min(min(q[x], p[y]) * 2 + max(q[x], p[y]), foo)
    return foo

def main():
    n, k = [int(i) for i in raw_input().strip().split()]
    a = [int(i) for i in raw_input().strip().split()]
    print(solution(a, k))

if __name__ == '__main__':
    main()
