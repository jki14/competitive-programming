from sys import stdout


def solution(a):
    print("%s" % ("Yes" if "A" in a and "B" in a and "C" in a else "No"))


def main():
    while True:
        try:
            a = input().strip()
        except ValueError:
            continue
        except EOFError:
            break
        if len(a) != 3:
            continue
        solution(a)


if __name__ == '__main__':
    main()
