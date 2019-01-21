from sys import stdout

class Result:
    
    class Edge:
        
        def __init__(self, u, v, w):
            self.u, self.v, self.w = u, v, w

    def __init__(self):
        self.d = 0
        self.e = []

    def append(self, u, v, w):
        self.e.append(self.Edge(u, v, w))

def solution(n, k):
    foo0 = Result()
    foo0.append(1, n, k)
    if n > 2 and k > 2:
        for v in xrange(2, n + 1):
            w = k - (v - 1)
            if w > 1:
                foo0.append(v - 1, v, w)
                foo0.d += w
            elif w == 1:
                foo0.append(v - 1, n, w)
                foo0.d += w
        foo0.d = abs(foo0.d - k)
    foo1 = Result()
    foo1.append(1, n, k)
    if n > 2 and k > 2:
        for v in xrange(n, 1, -1):
            w = n - v + 1
            if w < k - 1:
                foo1.append(v, v - 1, w)
                foo1.d += w
            elif w == k - 1:
                foo1.append(v, 1, w)
                foo1.d += w
        foo1.d = abs(foo1.d - k)
    if foo0.d > foo1.d:
        return foo0
    else:
        return foo1

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        n, k = [int(i) for i in raw_input().strip().split()]
        foo = solution(n, k)
        stdout.write('Case #%d: %d\n' % (case_id, foo.d))
        stdout.write('%d\n' % len(foo.e))
        for row in foo.e:
            stdout.write('%d %d %d\n' % (row.u, row.v, row.w))
        stdout.flush()

if __name__ == '__main__':
    main()
