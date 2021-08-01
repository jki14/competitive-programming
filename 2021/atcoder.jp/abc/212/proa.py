from sys import stdout


def solution(a, b):
    stdout.write('%s\n' % ('Alloy' if a > 0 and b > 0 else ('Gold' if a > 0 else 'Silver')))


def main():
    while True:
        try:
            a, b = [int(i) for i in raw_input().strip().split()]
            solution(a, b)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
