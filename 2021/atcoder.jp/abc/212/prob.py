from sys import stdout


def weak(a):
    return (sum([1 if a[i] == a[0] else 0 for i in range(4)]) == 4) or (sum([1 if int(a[i + 1]) == ((int(a[i]) + 1) % 10) else 0 for i in range(3)]) == 3)


def solution(a):
    if weak(a):
        stdout.write('Weak\n')
    else:
        stdout.write('Strong\n')


def main():
    while True:
        try:
            a = raw_input().strip()
            solution(a)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
