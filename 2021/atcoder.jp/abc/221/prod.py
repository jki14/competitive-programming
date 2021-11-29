from sys import stdout


def solution(a):
    n = len(a)
    b = [(e[0], 1) for e in a] + [(e[0] + e[1], -1) for e in a]
    b = sorted(b)
    m = len(b)
    c = 0
    r = [0 for i in xrange(n)]
    for i in xrange(m):
        c += b[i][1]
        if i == m - 1 or b[i][0] < b[i + 1][0]:
            if c > 0:
                r[c - 1] += (b[i + 1][0] - b[i][0]) if i < m - 1 else 1
    stdout.write(' '.join([str(i) for i in r]) + '\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            a = [tuple([int(j) for j in raw_input().strip().split()]) for i in xrange(n)]
            solution(a)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
