def finalLength(sample):
    foo = len(sample)
    tmp = 0
    for c in sample:
        if c=='S':
            tmp += 1
        elif tmp>0:
            tmp -= 1
            foo -= 2
    return foo

def main():
    sample = raw_input().strip()
    print finalLength(sample)

if __name__ == '__main__':
    main()
