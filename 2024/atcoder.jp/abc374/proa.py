from sys import stdout


def solution(a):
    if a.endswith("san"):
        stdout.write("Yes\n")
    else:
        stdout.write("No\n")


def main():
    while True:
        try:
            a = input().strip()
            if len(a) == 0:
                continue
        except EOFError:
            break
        solution(a, b)


if __name__ == '__main__':
    main()
