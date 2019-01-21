def main():
    s = raw_input().strip()
    k = int(raw_input().strip())
    for c in s:
        if k == 1:
            print c
            break
        if c == '1':
            k -= 1
        else:
            print c
            break

if __name__ == '__main__':
    main()
