import sys


def solution(n):
    foo = 0
    lef = 1
    while lef * lef <= n * 2:
        if n * 2 % lef != 0:
            continue
        rig = n * 2 / lef
        for l in set([lef, rig]):
            if (n * 2 / l + 1 - l) % 2 == 0:
                foo += 1
        lef += 1
    sys.stdout.write('%d\n' % foo)


def main():
    while True:
        try:
            n = int(raw_input().strip())
            solution(n)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
