from sys import stdout


def solution(a, b):
    if a == b:
        return 0
    n = min(len(a), len(b))
    for i in range(n):
        if a[i] != b[i]:
            return i + 1
    return n + 1


def main():
    while True:
        try:
            a = input().strip()
            if len(a) == 0:
                continue
            b = input().strip()
        except EOFError:
            break
        stdout.write("%d\n" % solution(a, b))


if __name__ == '__main__':
    main()
