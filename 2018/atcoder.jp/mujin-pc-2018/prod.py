from sys import stderr

class Solution:
    
    def __init__(self):
        self.vis = [[False for j in xrange(1000)] for i in xrange(1000)]
        self.foo = [[False for j in xrange(1000)] for i in xrange(1000)]
        self.ins = [[False for j in xrange(1000)] for i in xrange(1000)]
        for x in xrange(1000):
            self.vis[x][0] = True
        for y in xrange(1000):
            self.vis[0][y] = True
        for x in xrange(1000):
            for y in xrange(1000):
                self.solve(x, y)

    def solve(self, x, y):
        if not self.vis[x][y]:
            self.vis[x][y] = True
            self.ins[x][y] = True
            _x, _y = x, y
            if x < y:
                _x = int(str(x)[::-1])
            else:
                _y = int(str(y)[::-1])
            if _x < _y:
                _y -= _x
            else:
                _x -= _y
            if self.ins[_x][_y]:
                self.foo[x][y] = True
            else:
                self.foo[x][y] = self.solve(_x, _y)
            self.ins[x][y] = False
            return self.foo[x][y]
        else:
            return self.foo[x][y]

def main():
    solution = Solution()
    while True:
        try:
            n, m = [int(i) for i in raw_input().strip().split()]
            foo = 0
            for i in xrange(1, n + 1):
                for j in xrange(1, m + 1):
                    if solution.foo[i][j]:
                        foo += 1
            print(foo)
        except EOFError:
            break

if __name__ == '__main__':
    main()
