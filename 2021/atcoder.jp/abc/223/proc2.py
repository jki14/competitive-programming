from sys import stdout


def solution(x):
    s = str(x)
    stdout.write(('Yes' if s[-2:] == '00' else 'No') + '\n')


def main():
    while True:
        try:
            x = int(raw_input().strip())
            solution(x)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
