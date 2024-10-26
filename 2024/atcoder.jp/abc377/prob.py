from sys import stdout


def solution(a):
    r = [0 if '#' in a[i] else 1 for i in range(8)]
    c = [1 if max(['#' == a[i][j] for i in range(8)]) == False else 0 for j in range(8)]
    print(sum(r) * sum(c))


def main():
    while True:
        try:
            r = input().strip()
        except ValueError:
            continue
        except EOFError:
            break
        if len(r) != 8:
            continue
        a = [r] + [input().strip() for i in range(7)]
        solution(a)


if __name__ == '__main__':
    main()
