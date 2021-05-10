from math import floor, sqrt
from sys import stderr, stdout


def init(l, r):
    if l == r:
        return 0, l, r
    if l < r:
        x, y, z = init(r, l)
        return x, z, y
    k = int(floor(sqrt((l - r) * 2))) - 1
    while (k + 1) * (k + 2) <= (l - r) * 2:
        k += 1
    return k, l - k * (k + 1) / 2, r


def cost2(s, e):
    if s > e:
        return 0
    e = e - 1 if (s & 1) != (e & 1) else e
    k = (e - s) / 2 + 1
    return (s + e) * k / 2


def okay(s, e, l, r):
    return cost2(s, e) <= l and cost2(s + 1, e) <= r


def solution():
    l, r = [int(i) for i in raw_input().strip().split()]
    k, l, r = init(l, r)
    if l < r:
        if r >= k + 1:
            k += 1
            r -= k
        else:
            return k, l, r
    dis = 1
    while okay(k + 1, k + dis, l, r):
        dis *= 2
    low = k
    hig = k + dis
    while low < hig:
        mid = (low + hig) >> 1
        if okay(k + 1, mid + 1, l, r):
            low = mid + 1
        else:
            hig = mid
    return low, l - cost2(k + 1, low), r - cost2(k + 2, low)


def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        k, l, r = solution()
        stdout.write('Case #%d: %d %d %d\n' % (i + 1, k, l, r))


if __name__ == '__main__':
    main()
