def minimumOpt1(seq):
    dest = {}
    b = sorted(seq)
    for i in xrange(len(b)):
        dest[b[i]] = i
    foo = 0
    for i in xrange(0, len(seq), 2):
        if dest[seq[i]]%2==1:
            foo += 1
    return foo

def main():
    n = int(raw_input().strip())
    seq = [0] * n
    for i in xrange(n):
        seq[i] = int(raw_input().strip())
    print minimumOpt1(seq)

if __name__ == '__main__':
    main()
