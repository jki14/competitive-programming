def solution(a, s):
    if a == 0:
        return True
    for c in s:
        if c == '+':
            a += 1
        else:
            a -= 1
        if a == 0:
            return True
    if a == 0:
        return True
    else:
        return False

def main():
    while True:
        try:
            a = int(raw_input().strip())
            s = raw_input().strip()
            if solution(a, s):
                print('Yes')
            else:
                print('No')
        except EOFError:
            break

if __name__ == '__main__':
    main()
