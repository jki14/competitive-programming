import sys

def solution():
    n = int(input().strip())
    a = [tuple(int(j) + 100000000 for j in input().strip().split()) for i in range(n)]
    if n == 2:
        sys.stdout.write('%d\n%d\n' % (1, 1))
        return
    while True:
        cnt = [[0, 0], [0, 0]]
        for p in a:
            cnt[p[0] & 1][p[1] & 1] += 1
        if max(map(max, cnt)) == n:
            dx = a[0][0] & 1
            dy = a[0][1] & 1
            for i in range(n):
                a[i] = ((a[i][0] - dx) >> 1, (a[i][1] - dy) >> 1)
            continue
        if cnt[0][0] + cnt[1][1] > 0 and cnt[0][0] + cnt[1][1] < n:
            sys.stdout.write('%d\n' % (cnt[0][0] + cnt[1][1]))
            first = True
            for i in range(n):
                if (a[i][0] & 1) == (a[i][1] & 1):
                    if not first:
                        sys.stdout.write(' ')
                    else:
                        first =False
                    sys.stdout.write('%d' % (i + 1))
            sys.stdout.write('\n')
            return
        else:
            sys.stdout.write('%d\n' % (cnt[0][0] + cnt[0][1]))
            first = True
            for i in range(n):
                if (a[i][0] & 1) == 0:
                    if not first:
                        sys.stdout.write(' ')
                    else:
                        first = False
                    sys.stdout.write('%d' % (i + 1))
            sys.stdout.write('\n')
            return

def main():
    solution()

if __name__ == '__main__':
    main()
