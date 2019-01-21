def main():
    s = raw_input().strip()
    if len(s) >= 5 and s[:5] == 'MUJIN':
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()
