import sys


def solution(a, m):
    n = len(a)
    c = { }
    for d in a:
        if d not in c:
            c[d] = 1
        else:
            c[d] = c[d] + 1
    bar = [c[k] for k in sorted(c.keys())]
    foo = m - 1
    if [i for i in bar if i >= m]:
        foo = 0
    elif [i for i in bar[:-1] if i >= m - 1]:
        foo = 1
    elif m == 3 and [ k for k in c.keys() if k * 2 in c]:
        foo = 1
    return foo


def process(case_id):
    n, m = [int(i) for i in raw_input().strip().split()]
    a = [int(i) for i in raw_input().strip().split()]
    sys.stdout.write('Case #%d: %d\n' % (case_id, solution(a, m)))
    

def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        process(i + 1)


if __name__ == '__main__':
    main()
