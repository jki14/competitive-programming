import sys

inf = 2 ** 30

def solution(a):
    n = len(a)
    foo = n * n
    good = [False for i in range(n)]
    for i in range(n):
        prev = inf
        for v in a[i]:
            if v < prev:
                prev = v
            elif v > prev:
                good[i] = True
                break
    a = [a[i] for i in range(n) if not good[i]]
    n = len(a)

    minv = [min(row) for row in a]
    maxv = [max(row) for row in a]

    minv = sorted(minv)
    maxv = sorted(maxv)

    j = 0
    for i in range(n):
        while j < n and minv[i] >= maxv[j]:
            j += 1
        foo -= j

    sys.stdout.write('%d\n' % foo)

def main():
    while True:
        try:
            n = int(input().strip())
            a = [[int(j) for j in input().strip().split()][1:] for i in range(n)]
            solution(a)
        except ValueError:
            continue
        except EOFError:
            break

if __name__ == '__main__':
    main()
