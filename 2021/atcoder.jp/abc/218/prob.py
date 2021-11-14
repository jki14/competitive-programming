from sys import stdout


def solution(s):
    stdout.write(''.join([chr(ord('a') + i - 1) for i in s]) + '\n')


def main():
    while True:
        try:
            s = [int(i) for i in raw_input().strip().split()]
            solution(s)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
