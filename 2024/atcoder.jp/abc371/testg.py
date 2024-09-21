from sys import stderr, stdout

def check(x):
    for i in range(2, x):
        if i * i > x:
            break
        if x % i == 0:
            return False
    return True


def main():
    n = 200000
    stdout.write('%d\n' % n)
    p = [0 for i in range(n)]
    a = [0 for i in range(n)]
    prm, pos = 1, 0
    while pos < n:
        prm += 1
        while not check(prm):
            prm += 1
        length = min(prm, n - pos)
        for i in range(length):
            p[pos + i] = pos + (i + 1) % length
            a[pos + i] = pos + length - i - 1
        pos += length
    stdout.write(' '.join([str(i + 1) for i in p]) + '\n')
    stdout.write(' '.join([str(i + 1) for i in a]) + '\n')


if __name__ == '__main__':
    main()
