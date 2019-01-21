def count(seq):
    seq = sorted(seq)
    arrived = {}
    arrived[seq[0]] = {}
    arrived[seq[0]][seq[1]] = True
    foo = 0
    s = sum(seq)
    while True:
        if (seq[0]&1==1) or (seq[1]&1==1) or (seq[2]&1==1):
            break
        seq = [(s-seq[i])>>1 for i in xrange(3)]
        seq = sorted(seq)
        if seq[0] in arrived.keys():
            if seq[1] in arrived[seq[0]].keys():
                foo = -1
                break
        else:
            arrived[seq[0]] = {}
        arrived[seq[0]][seq[1]] = True
        foo += 1
    return foo

def main():
    seq = [int(x) for x in raw_input().strip().split()]
    print count(seq)

if __name__ == '__main__':
    main()
