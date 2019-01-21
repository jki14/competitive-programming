from sys import stderr
from sys import stdout

mod = 1000000007

def extended_euclidean(a, b):
    if b != 0:
        g, x, y = extended_euclidean(b, a % b)
        return g, y, x - a / b * y
    else:
        return a, 1, 0

def inversee(a, b):
    return extended_euclidean(a, b)[1]

class Factorial:
    def __init__(self):
        self.foo = []
        self.foo.append(1)
    def calc(self, x):
        while len(self.foo) <= x:
            self.foo.append(self.foo[-1] * len(self.foo) % mod)
        return self.foo[x]

factorial = Factorial()

class Accelerator:
    def __init__(self):
        self.f = 0
        self.l = 0
        self.r = 1
        #self.cost = 0
    def calc(self, f, l):
        if self.l != l or abs(self.f - f) > l:
            self.f = f
            self.l = l
            self.r = 1
            for i in xrange(l):
                self.r = self.r * (f - i) % mod
            #self.cost += l
        else:
            while self.f < f:
                self.f += 1
                self.r = self.r * self.f % mod
                self.r = self.r * inversee(self.f - l, mod) % mod
                #self.cost += 1
            while self.f > f:
                self.r = self.r * (self.f - l) % mod
                self.r = self.r * inversee(self.f, mod) % mod
                self.f -= 1
                #self.cost += 1
        #stderr.write('accelerator.calc(%d, %d) = %d\n' % (f, l, self.r))
        return self.r

accelerator = Accelerator() 

def solution(rs, m):
    n = len(rs)
    if m == 1:
        if n == 1:
            return 1
        else:
            return 0
    if n == 1:
        return m
    s = sum(rs) * 2
    sub = []
    for i in xrange(n):
        for j in xrange(i + 1, n):
            free = m - 1 - (s - rs[i] - rs[j])
            if free >= 0:
                sub.append(free + n)
    foo = 0
    for i in sorted(sub):
        foo = (foo + 2 * factorial.calc(n - 2) * accelerator.calc(i, n) * inversee(factorial.calc(n), mod) % mod) % mod
    return foo

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(case_num):
        n, m = [int(i) for i in raw_input().strip().split()]
        rs = [int(raw_input().strip()) for i in xrange(n)]
        #accelerator.cost = 0
        stdout.write('Case #%d: %d\n' % (case_id + 1, solution(rs, m)))
        stdout.flush()
        #stderr.write('cost = %d\n' % (accelerator.cost))
        #stderr.flush()

if __name__ == '__main__':
    main()
