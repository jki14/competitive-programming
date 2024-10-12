from sys import stdout


def solution(a, n):
    foo = 0
    for i in range(n - 2):
        if a[i:i + 3] == '#.#':
            foo += 1
    stdout.write("%d\n" % foo)


def main():
    while True:
        try:
            n = int(input().strip())
            a = input().strip()
            solution(a, n)
        except ValueError:
            continue
        except EOFError:
            break


if __name__ == '__main__':
    main()
