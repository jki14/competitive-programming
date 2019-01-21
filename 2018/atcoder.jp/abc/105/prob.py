def main():
    n = int(raw_input().strip())
    y = 0
    while 7 * y <= n:
        if (n - 7 * y) % 4 == 0:
            print 'Yes'
            return
        y += 1
    print 'No'

if __name__ == '__main__':
    main()
