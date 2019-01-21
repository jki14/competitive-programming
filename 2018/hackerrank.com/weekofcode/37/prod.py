def main():
    n = int(raw_input().strip())
    pos = []
    neg = []
    for i in xrange(n):
        raw = raw_input().strip().split()
        if raw[0] == '+':
            pos.append((int(raw[1]), int(raw[2])))
        elif raw[0] == '-':
            neg.append((int(raw[1]), int(raw[2])))
        else:
            y = int(raw[1])
            foo = 0
            for obj in pos:
                if (y-obj[1])%obj[0] == 0:
                    foo += 1
            for obj in neg:
                if (y-obj[1])%obj[0] == 0:
                    foo -= 1
            print foo

if __name__ == '__main__':
    main()
