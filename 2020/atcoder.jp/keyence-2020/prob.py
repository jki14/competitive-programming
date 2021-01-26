import sys

class Point:
    def __init__(self, x = 0, y = 0):
        self.x, self.y = x, y
    
    def next(self, mata, matb):
        return Point(self.x * mata.x + matb.x, self.y * mata.y + matb.y)

    def dist(self, rhs):
        return abs(self.x - rhs.x) + abs(self.y - rhs.y)
    
    def __str__(self):
        return '(%d, %d)' % (self.x, self.y)

def left(a, post, dist):
    # sys.stderr.write('%s\n' % ' '.join([str(x) for x in a]))
    foo = 0
    # lef first
    key, bar, wht = 0, 0, 0
    while bar < len(a):
        bar += 1
        if bar == 1:
            wht += post.dist(a[key + bar - 1])
        elif key + bar - 1 < len(a):
            wht += a[key + bar - 2].dist(a[key + bar - 1])
        else:
            wht += post.dist(a[key - 1]) - post.dist(a[key])\
                    + a[key - 1].dist(a[key])
            key -= 1
        while key > 0:
            det = post.dist(a[key - 1]) - post.dist(a[key])\
                    + a[key - 1].dist(a[key])\
                    - a[key + bar - 2].dist(a[key + bar - 1])
            if det <= 0:
                wht += det
                key -= 1
            else:
                break
        while key + bar < len(a):
            det = post.dist(a[key + 1]) - post.dist(a[key])\
                    + a[key + bar - 1].dist(a[key + bar])\
                    - a[key].dist(a[key + 1])
            if det <= 0:
                wht += det
                key += 1
            else:
                break
        # sys.stderr.write('key = %d, bar = %d, wht = %d\n' % (key, bar, wht))
        if wht <= dist:
            foo = max(bar, foo)
        else:
            break
    return foo

def solution(zero, mata, matb, post, dist):
    a = [None for i in range(128)]
    a[0] = zero
    for i in range(1, 128):
        a[i] = a[i - 1].next(mata, matb)
        if a[i].x > post.x + dist or a[i].y > post.y + dist:
            break
    a = [x for x in a if x is not None]
    return max(left(a, post ,dist), left(a[::-1], post, dist))
    
def main():
    while True:
        try:
            x0, y0, ax, ay, bx, by = [int(i) for i in input().strip().split()]
            zero = Point(x0, y0)
            mata = Point(ax, ay)
            matb = Point(bx, by)
            x, y, d = [int(i) for i in input().strip().split()]
            post = Point(x, y)
            sys.stdout.write('%d\n' % solution(zero, mata, matb, post, d))
        except ValueError:
            continue
        except EOFError:
            break

if __name__ == '__main__':
    main()
