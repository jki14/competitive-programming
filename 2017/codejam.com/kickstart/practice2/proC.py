
def calc(x, y):
    return (pow(x, y) - 1) / (x - 1)

def check(x, y):
    lef, rig = 2, 2
    while calc(rig, x) < y:
        lef, rig = rig + 1, rig * 2
    while lef < rig:
        mid = (lef + rig) / 2
        if calc(mid, x) >= y:
            rig = mid
        else:
            lef = mid + 1
    #print('calc(%d, %d) = %d (%d)\n', lef, x, calc(lef, x), y)
    if calc(lef, x) == y:
        return lef
    else:
        return 0

def process(y):
    for i in xrange(60, 0, -1):
        tmp = check(i, y)
        if tmp != 0:
            return tmp

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        y = int(raw_input().strip())
        print('Case #%d: %d' % (i + 1, process(y)))

if __name__ == '__main__':
    main()
