def main():
    n = int(raw_input().strip())
    a = [int(raw_input().strip()) for i in xrange(n)]
    a = [a[i] for i in xrange(n) if a[i]>=90]
    print('%.2f' % (round(sum(a)*1.0/len(a), 2)))

if __name__ == '__main__':
    main()
