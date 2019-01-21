class City:
    def __self__(self, prefecture = 0, year = 0, rowid = 0):
        self.prefecture = prefecture
        self.year = year
        self.rowid = rowid
    def __lt__(self, rhs):
        if self.prefecture < rhs.prefecture or (self.prefecture == rhs.prefecture and self.year < rhs.year):
            return True
        return False

def solution(cities):
    n = len(cities)
    foo = [None for i in range(n)]
    cities = sorted(cities)
    prev, offset = -1, 0
    for i in range(n):
        if cities[i].prefecture != prev:
            prev = cities[i].prefecture
            offset = 1
        foo[cities[i].rowid] = '%06d%06d' % (cities[i].prefecture, offset)
        offset += 1
    return foo

def main():
    n, m = [int(i) for i in input().strip().split()]
    cities = [City() for i in range(m)]
    for i in range(m):
        p, y = [int(i) for i in input().strip().split()]
        cities[i].prefecture = p
        cities[i].year = y
        cities[i].rowid = i
    foo = solution(cities)
    for row in foo:
        print(row)

if __name__ == '__main__':
    main()
