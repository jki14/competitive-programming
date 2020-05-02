import sys


def solution(x, y, path):
    dx = { 'E': 1, 'N': 0, 'W': -1, 'S': 0 }
    dy = { 'E': 0, 'N': 1, 'W': 0, 'S': -1 }
    for i in xrange(len(path)):
        k = path[i]
        x += dx[k]
        y += dy[k]
        if abs(x) + abs(y) <= i + 1:
            return str(i + 1)
    return 'IMPOSSIBLE'


def process(case_id):
    x, y, path = [i for i in raw_input().strip().split()]
    x, y = int(x), int(y)
    sys.stdout.write('Case #%d: %s\n' % (case_id, solution(x, y, path)))
    

def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        process(i + 1)


if __name__ == '__main__':
    main()
