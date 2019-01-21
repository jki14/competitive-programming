def solution(a, b):
    #todo: check if a and b are valid
    if (a + a[:-1]).find(b) >= 0:
        return 'Yes'
    else:
        return 'No'

def main():
    a = raw_input().strip()
    b = raw_input().strip()
    print solution(a, b)

if __name__ == '__main__':
    main()