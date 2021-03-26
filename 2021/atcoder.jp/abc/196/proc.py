from sys import stdout


def solution(n):
    cnt = 0
    foo = 1
    while True:
        bar = int(str(foo) + str(foo))
        if bar <= n:
            cnt += 1
        else:
            break
        foo += 1
    stdout.write('%d\n' % cnt)


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
