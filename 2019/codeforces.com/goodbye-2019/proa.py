def main():
    case_num = int(input())
    for k in range(case_num):
        s, n, m = [int(i) for i in input().strip().split()]
        lef = [int(i) for i in input().strip().split()]
        rig = [int(i) for i in input().strip().split()]
        if max(lef) > max(rig):
            print('YES')
        else:
            print('NO')

if __name__ == '__main__':
    main()
