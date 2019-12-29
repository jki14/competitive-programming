import sys

def solution():
    n, k = [int(i) for i in input().strip().split()]
    foo = '? ' + ' '.join([str(i + 1) for i in range(k)]) + ' '
    bar = ' ' + str(k + 1) + ' '
    sys.stdout.write(foo.strip() + '\n')
    sys.stdout.flush()
    p, w = [int(i) - 1 for i in input().strip().split()]
    lt, eq, gt = 0, 0, 0
    for i in range(k):
        if i == p:
            continue
        sys.stdout.write(foo.replace(' ' + str(i + 1) + ' ', bar).strip() + '\n')
        sys.stdout.flush()
        q, v = [int(i) - 1 for i in input().strip().split()]
        if v < w:
            lt += 1
        elif v > w:
            gt += 1
        else:
            eq += 1
    if lt != 0:
        sys.stdout.write('! %d\n' % (k - lt))
        sys.stdout.flush()
        return
    elif gt!= 0:
        sys.stdout.write('! %d\n' % (gt + 1))
        sys.stdout.flush()
        return
    sys.stdout.write(foo.replace(' ' + str(p + 1) + ' ', bar).strip() + '\n')
    q, v = [int(i) - 1 for i in input().strip().split()]
    if v < w:
        sys.stdout.write('! %d\n' % (k))
        sys.stdout.flush()
    else:
        sys.stdout.write('! %d\n' % (1))
        sys.stdout.flush()

def main():
    solution()

if __name__ == '__main__':
    main()
