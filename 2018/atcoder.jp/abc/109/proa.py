def solution(a, b):
    if (a & 1) == 1 and (b & 1) == 1:
        return True
    else:
        return False

def main():
    a, b = [int(i) for i in raw_input().strip().split()]
    if solution(a, b):
        print 'Yes'
    else:
        print 'No'

if __name__ == '__main__':
    main()
