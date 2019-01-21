class Point2d:
    
    def __init__(self, x, y):
        self.x, self.y = x, y

def get3rd(p0, p1):
    return Point2d(p1.x + p0.y - p1.y, p1.y + p1.x - p0.x)

def solution(p0, p1):
    p2 = get3rd(p0, p1)
    p3 = get3rd(p1, p2)
    return p2, p3

def main():
    raw = [int(i) for i in raw_input().strip().split()]
    p2, p3 = solution(Point2d(raw[0], raw[1]), Point2d(raw[2], raw[3]))
    print '%d %d %d %d' % (p2.x, p2.y, p3.x, p3.y)

if __name__ == '__main__':
    main()
