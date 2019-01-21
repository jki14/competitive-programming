from heapq import heappush
from heapq import heappop

class cake:
    def __init__(self, x, y, z):
        self.x, self.y, self.z = x, y, z
    def score(self, x, y, z):
        return self.x * x + self.y * y + self.z *z

def solution(cakeList, m):
    foo = 0
    for x in xrange(-1, 2, 2):
        for y in xrange(-1, 2, 2):
            for z in xrange(-1, 2, 2):
                cache = []
                for el in cakeList:
                    heappush(cache, el.score(x, y, z))
                    while len(cache) > m:
                        heappop(cache)
                foo = max(sum(cache), foo)
    return foo

def main():
    n, m = [int(i) for i in raw_input().strip().split()]
    cakeList = []
    for i in xrange(n):
        x, y, z = [int(i) for i in raw_input().strip().split()]
        cakeList.append(cake(x, y, z))
    print solution(cakeList, m)

if __name__ == '__main__':
    main()
