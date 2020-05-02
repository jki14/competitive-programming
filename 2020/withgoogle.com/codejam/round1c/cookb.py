def main():
    t = int(raw_input().strip())
    print(t)
    n = int(raw_input().strip())
    print(n)
    for i in xrange(10000):
        lef, rig = [j for j in raw_input().strip().split()]
        print('-1 %s' % rig)


if __name__ == '__main__':
    main()
