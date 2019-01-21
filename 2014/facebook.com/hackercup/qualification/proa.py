from sys import stdout

def solution(a):
    #TODO: check if a is valid
    n = len(a)
    xr, yr = [n, -1], [n, -1]
    for x in xrange(n):
        for y in xrange(n):
            if a[x][y] == '#':
                xr[0] = min(x, xr[0])
                xr[1] = max(x, xr[1])
                yr[0] = min(y, yr[0])
                yr[1] = max(y, yr[1])
    if xr[0] == n or xr[1] - xr[0] != yr[1] - yr[0]:
        return False
    for x in xrange(xr[0], xr[1] + 1):
        for y in xrange(yr[0], yr[1] + 1):
            if a[x][y] != '#':
                return False
    return True

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        n = int(raw_input().strip())
        a = [raw_input().strip() for i in xrange(n)]
        if solution(a):
            stdout.write('Case #%d: YES\n' % case_id)
        else:
            stdout.write('Case #%d: NO\n' % case_id)
        stdout.flush()

if __name__ == '__main__':
    main()
