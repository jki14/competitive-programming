from sys import stdout


def solution(s):
    n = len(s)
    d = {}
    for p in s:
        if p[0] not in d:
            d[p[0]] = {}
        d[p[0]][p[1]] = True
    res = 0
    for p in s:
        for q in s:
            if p[0] < q[0] and p[1] < q[1]:
                if q[1] in d[p[0]]:
                    if p[1] in d[q[0]]:
                        res += 1
    stdout.write('%d\n' % res)
    return 0


def main():
    while True:
        try:
            n = int(raw_input().strip())
            s = [tuple([int(j) for j in raw_input().strip().split()]) for i in xrange(n)]
            solution(s)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
