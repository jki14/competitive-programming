def solution(s):
    #todo: check if s is valid
    if s[0] == 'A' and sum([1 for c in s if c =='C']) == 1 and sum([1 for c in s[2:-1] if c =='C']) == 1 and sum([1 for c in s if ord(c) <= ord('Z')]) == 2:
        return 'AC'
    return 'WA'

def main():
    s = raw_input().strip()
    print solution(s)

if __name__ == '__main__':
    main()