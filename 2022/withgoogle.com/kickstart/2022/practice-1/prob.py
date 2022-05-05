from sys import stdout


def handler():
    bar = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
    a = input().strip()
    if a[-1] == 'y' or a[-1] == 'Y':
        stdout.write('%s is ruled by nobody.\n' % a)
    elif a[-1] in bar:
        stdout.write('%s is ruled by Alice.\n' % a)
    else:
        stdout.write('%s is ruled by Bob.\n' % a)


def main():
    t = int(input().strip())
    for i in range(t):
        stdout.write('Case #%d: ' % (i + 1))
        handler()


if __name__ == '__main__':
    main()
