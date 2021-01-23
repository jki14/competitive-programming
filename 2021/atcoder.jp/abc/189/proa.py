def main():
    a = raw_input().strip()
    if a[0] == a[1] and a[1] == a[2]:
        print('Won')
    else:
        print('Lost')


if __name__ == '__main__':
    main()
