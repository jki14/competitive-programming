from sys import stdout


def solution(a):
    f = [a.count(i + 1) for i in range(4)]
    print(sum([e // 2 for e in f]))


def main():
    while True:
        try:
            a = [int(i) for i in input().strip().split()]
        except ValueError:
            continue
        except EOFError:
            break
        if len(a) != 4:
            continue
        solution(a)


if __name__ == '__main__':
    main()
