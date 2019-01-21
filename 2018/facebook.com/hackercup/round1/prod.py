from sys import stderr
from sys import stdout

MOD = 1000000007

def extended_euclidean(a, b):
    if b != 0:
        g, x, y = extended_euclidean(b, a % b)
        return g, y, x - a / b * y
    else:
        return a, 1, 0


cheatsheet = [extended_euclidean(i, MOD)[1] for i in xrange(1000001)]
def inversee(a):
    return cheatsheet[a]

class Fence:

    def __init__(self, a, b):
        self.a, self.b = a, b

    def range_probability(self, a, b):
        a = max(a, self.a)
        b = min(b, self.b)
        if a > b:
            return 0
        else:
            return ((b - a + 1) * inversee(self.b - self.a + 1) % MOD + MOD) % MOD


class Zombie:

    def __init__(self, y, h):
        self.y, self.h = y, h


def solution(fences, zombies):
    heights = {0: 0, 1000001: 0}
    for zombie in zombies:
        heights[zombie.h] = 0
    n = len(fences) + 1
    m = 0
    for key in sorted(heights.keys()):
        heights[key] = m
        m += 1
    a = [0 for i in xrange(n)]
    for zombie in zombies:
        a[zombie.y - 1] = max(heights[zombie.h], a[zombie.y - 1])
    heights = {value: key for key, value in heights.iteritems()}
    heights = [heights[i] for i in xrange(m)]
    ''' - Incorrect Algorithm
    g = [[0 for j in xrange(m)] for i in xrange(n)]
    g[n - 1][a[n - 1]] = 1
    for i in xrange(n - 2, -1, -1):
        g[i][a[i]] = 1
        for j in xrange(m - 1, a[i], -1):
            g[i][j] = g[i + 1][j] * fences[i].pass_probability(heights[j]) % MOD
            g[i][a[i]] = (g[i][a[i]] - g[i][j] + MOD) % MOD
    f = [[0 for j in xrange(m)] for i in xrange(n)]
    f[0][a[0]] = 1
    for i in xrange(n - 1):
        f[i + 1][a[i + 1]] = 0
        for j in xrange(1, m):
            f[i + 1][a[i + 1]] = (f[i + 1][a[i + 1]] + f[i][j]) % MOD
        for j in xrange(m - 1, a[i + 1], -1):
            f[i + 1][j] = f[i][j] * fences[i].pass_probability(heights[j]) % MOD
            f[i + 1][a[i + 1]] = (f[i + 1][a[i + 1]] - f[i + 1][j] + MOD) % MOD
    foo = 0
    for i in xrange(n):
        stderr.write('f[%d][0] = %d, g[%d][0] = %d\n' % (i, f[i][0], i, g[i][0]))
        foo = (foo + f[i][0] * g[i][0] % MOD) % MOD
    return foo
    '''
    f = [[0 for j in xrange(m)] for i in xrange(n)]
    g = [[0 for j in xrange(m)] for i in xrange(n)]
    if a[0] == 0:
        f[0][0] = 1
    else:
        g[0][a[0]] = 1
    for i in xrange(1, n):
        if a[i] == 0:
            #keep-safe
            tmp = 0
            for j in xrange(m):
                f[i][j] = (f[i][j] + f[i - 1][j] * fences[i - 1].range_probability(0, heights[j])) % MOD
                f[i][j] = (f[i][j] + tmp * fences[i - 1].range_probability(heights[j - 1] + 1, heights[j])) % MOD
                tmp = (tmp + f[i - 1][j]) % MOD
            #turn-safe
            for j in xrange(m):
                f[i][0] = (f[i][0] + g[i - 1][j] * fences[i - 1].range_probability(heights[j] + 1, 1000001)) %MOD
            #keep-danger
            for j in xrange(m):
                g[i][j] = (g[i][j] + g[i - 1][j] * fences[i - 1].range_probability(0, heights[j])) % MOD
        else:
            #safe
            tmp = 0
            for j in xrange(a[i] + 1):
                tmp = (tmp + f[i - 1][j]) % MOD
            for j in xrange(a[i] + 1, m):
                f[i][j] = (f[i][j] + f[i - 1][j] * fences[i - 1].range_probability(0, heights[j])) % MOD
                f[i][j] = (f[i][j] + tmp * fences[i - 1].range_probability(heights[j - 1] + 1, heights[j])) % MOD
                tmp = (tmp + f[i - 1][j]) % MOD
            #danger
            for j in xrange(a[i] + 1):
                g[i][a[i]] = (g[i][a[i]] + g[i - 1][j]) % MOD
                g[i][a[i]] = (g[i][a[i]] + f[i - 1][j] * fences[i - 1].range_probability(0, heights[a[i]])) % MOD
            for j in xrange(a[i] + 1, m):
                g[i][a[i]] = (g[i][a[i]] + g[i - 1][j] * fences[i - 1].range_probability(heights[j] + 1, 1000001)) % MOD
                g[i][j] = (g[i][j] + g[i - 1][j] * fences[i - 1].range_probability(0, heights[j])) % MOD
    foo = 0
    for j in xrange(m):
        foo = (foo + f[n - 1][j]) % MOD
    return foo

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        while True:
            try:
                n, m = [int(i) for i in raw_input().strip().split()]
            except ValueError:
                continue
            break
        fences = [Fence(0, 0) for i in xrange(n - 1)]
        for fence in fences:
            fence.a, fence.b = [int(i) for i in raw_input().strip().split()]
        zombies = [Zombie(0, 0) for i in xrange(m)]
        for zombie in zombies:
            zombie.y, zombie.h = [int(i) for i in raw_input().strip().split()]
        print('Case #%d: %d' % (case_id, solution(fences, zombies)))
        stdout.flush()

if __name__ == '__main__':
    main()
