import sys

def unique(a):
    s = set(a)
    return len(a) == len(s)


def solution(mat):
    n = len(mat)
    k = sum([mat[i][i] for i in xrange(n)])
    r = sum([1 for i in xrange(n) if not unique([mat[i][j] for j in xrange(n)])])
    c = sum([1 for i in xrange(n) if not unique([mat[j][i] for j in xrange(n)])])
    return k, r, c


def process(case_id):
    n = int(raw_input().strip())
    mat = [[int(j) for j in raw_input().strip().split()] for i in xrange(n)]
    k, r, c = solution(mat)
    sys.stdout.write('Case #%d: %d %d %d\n' % (case_id, k, r, c))
    

def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        process(i + 1)


if __name__ == '__main__':
    main()
