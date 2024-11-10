from sys import stdout


def resolve(d, q, r):
    if d % q == r:
        return 0
    return (r - d % q + q) % q


def solution(n):
    q = [0 for i in range(n)]
    r = [0 for i in range(n)]
    for i in range(n):
        q[i], r[i] = [int(e) for e in input().strip().split()]
    m = int(input().strip())
    for i in range(m):
        k, d = [int(e) for e in input().strip().split()]
        print(d + resolve(d, q[k - 1], r[k - 1]))


def main():
    while True:
        try:
            n = int(input().strip())
        except ValueError:
            continue
        except EOFError:
            break
        solution(n)


if __name__ == '__main__':
    main()
