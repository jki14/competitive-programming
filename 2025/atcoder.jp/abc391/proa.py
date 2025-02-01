from sys import stdout


def solution(a):
    stdout.write(a.replace('N', 's').replace('E', 'w').replace('W', 'e').replace('S', 'n').upper() + '\n')


def main():
    while True:
        try:
            a = input().strip()
        except ValueError:
            continue
        except EOFError:
            break
        if len(a) == 0:
            continue
        solution(a)


if __name__ == '__main__':
    main()
