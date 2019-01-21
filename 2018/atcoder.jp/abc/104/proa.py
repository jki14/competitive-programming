def solution(r):
    #todo: check if r is valid
    if r < 1200:
        return 'ABC'
    elif r < 2800:
        return 'ARC'
    else:
        return 'AGC'

def main():
    r = int(raw_input().strip())
    print solution(r)

if __name__ == '__main__':
    main()