from sys import stdout


def dfs(u, neighbors, prev, p, seq):
    seq.append(u)
    prev[u] = p
    for v in neighbors[u]:
        if prev[v] < 0:
            dfs(v, neighbors, prev, u, seq)
            seq.append(u)


def solution(e, n):
    prev = [-1 for i in xrange(n)]
    neighbors = [[] for i in xrange(n)]
    for r in e:
        u, v = r
        neighbors[u].append(v)
        neighbors[v].append(u)
    for i in xrange(n):
        neighbors[i].sort()
    seq = []
    dfs(0, neighbors, prev, 0, seq)
    stdout.write('%s\n' % (' '.join([str(i + 1) for i in seq])))


def main():
    while True:
        try:
            n = int(raw_input().strip())
            e = [tuple([int(j) - 1 for j in raw_input().strip().split()]) for i in xrange(n - 1)]
            solution(e, n)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
