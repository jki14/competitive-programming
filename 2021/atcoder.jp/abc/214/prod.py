from sys import setrecursionlimit
from sys import stdout


def find(u, f):
    if f[u] != u:
        f[u] = find(f[u], f)
    return f[u]


def solution(edges):
    edges.sort(cmp = lambda lhs, rhs: lhs[2] - rhs[2] if lhs[2] != rhs[2] else (lhs[0] - rhs[0] if lhs[0] != rhs[0] else lhs[1] - rhs[1]))
    edges = [(e[0] - 1, e[1] - 1, e[2]) for e in edges]
    n = len(edges) + 1
    f = [i for i in xrange(n)]
    c = [1 for i in xrange(n)]
    bar = 0
    for e in edges:
        u = find(e[0], f)
        v = find(e[1], f)
        bar += c[u] * c[v] * e[2]
        f[v] = u
        c[u] += c[v]
    stdout.write('%d\n' % bar)


def main():
    while True:
        try:
            n = int(raw_input().strip())
            edges = [tuple([int(j) for j in raw_input().strip().split()]) for i in xrange(n - 1)]
            solution(edges)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    setrecursionlimit(1048576)
    main()
