from sys import stdout
from sys import stderr


def solution(n, k, cuts):
    modulo = 998244353
    cuts = [(entry[0] - 1, entry[1] - 1) for entry in cuts]
    curr = [1 if i == 0 else 0 for i in xrange(n)]
    for i in xrange(k):
        prev = [j for j in curr]
        total = sum(prev) % modulo
        curr = [total - prev[j] for j in xrange(n)]
        for entry in cuts:
            curr[entry[0]] = (curr[entry[0]] - prev[entry[1]]) % modulo
            curr[entry[1]] = (curr[entry[1]] - prev[entry[0]]) % modulo
    foo = (curr[0] % modulo + modulo) % modulo
    stdout.write('%d\n' % foo)


def main():
    while True:
        try:
            n, m, k = [int(i) for i in raw_input().strip().split()]
            cuts = [tuple([int(j) for j in raw_input().strip().split()]) for i in xrange(m)]
            solution(n, k, cuts)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
