from sys import stdout


def solution(a):
    foo = sum([1 if len(a[i]) == (i + 1) else 0 for i in range(12)])
    stdout.write("%d\n" % foo)


def main():
    while True:
        try:
            a = [input().strip() for i in range(12)]
        except EOFError:
            break
        solution(a)


if __name__ == '__main__':
    main()
