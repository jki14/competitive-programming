from sys import stdout


def ranking(r, w):
    return sorted(r, key = lambda x: (-w[x], x))


def game(lhs, rhs):
    if lhs == rhs:
        return 0
    seq = 'GCP'
    return 1 if seq.index(rhs) == (seq.index(lhs) + 1) % 3 else -1


def solution(c):
    n, m = len(c), len(c[0])
    r = [i for i in xrange(n)]
    w = [0 for i in xrange(n)]
    for k in xrange(m):
        for i in xrange(0, n, 2):
            lhs, rhs = r[i], r[i + 1]
            wl = game(c[lhs][k], c[rhs][k])
            if wl > 0:
                w[lhs] += 1
            elif wl < 0:
                w[rhs] += 1
        r = ranking(r, w)
    stdout.write('\n'.join([str(i + 1) for i in r]) + '\n')


def main():
    while True:
        try:
            n, m = [int(i) for i in raw_input().strip().split()]
            c = [[j for j in raw_input().strip()] for i in xrange(n * 2)]
            solution(c)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
