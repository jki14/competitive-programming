from sys import stdout


def solution(s, t):
    foo = 0
    for x in xrange(s + 1):
        for y in xrange(s + 1 - x):
            for z in xrange(s + 1 - x - y):
                if x * y * z <= t:
                    foo += 1
    stdout.write('%d\n' % foo)


def main():
    while True:
        try:
            s, t = [int(i) for i in raw_input().strip().split()]
            solution(s, t)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
