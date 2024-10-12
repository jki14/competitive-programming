from sys import stdout


def rotate(a, k, n):
    head, tail = k, n - k - 1
    for i in range(tail - head):
        tmp = a[head][head + i]
        a[head][head + i] = a[tail - i][head]
        a[tail - i][head] = a[tail][tail - i]
        a[tail][tail - i] = a[head + i][tail]
        a[head + i][tail] = tmp


def simulate(a, k, r, n):
    for i in range(r):
        rotate(a, k, n)


def solution(a, n):
    for k in range(n // 2):
        simulate(a, k, (k + 1) % 4, n)
    stdout.write('\n'.join([''.join(r) for r in a]))
    stdout.write('\n')


def main():
    while True:
        try:
            n = int(input().strip())
            a = [list(input().strip()) for i in range(n)]
        except ValueError:
            continue
        except EOFError:
            break
        solution(a, n)


if __name__ == '__main__':
    main()
