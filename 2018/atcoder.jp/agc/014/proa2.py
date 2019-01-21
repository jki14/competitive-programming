def count(seq):
    seq = sorted(seq)
    if (seq[0] & 1) == 1 or (seq[1] & 1) == 1 or (seq[2] & 1) == 1:
        return 0
    x , y = [seq[1] - seq[0], seq[2] - seq[0]]
    if x == 0 and y == 0:
        return -1
    elif x == 0:
        k = x & -x
    elif y == 0:
        k = y & -y
    else:
        k = min(x & -x, y & -y)
    foo = 0
    while (k & 1) == 0:
        k >>= 1
        foo += 1
    return foo

def main():
    seq = [int(x) for x in raw_input().strip().split()]
    print count(seq)

if __name__ == '__main__':
    main()
