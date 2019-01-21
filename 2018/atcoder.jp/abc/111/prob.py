def solution(s):
    n = len(s)
    k = s[0]
    for i in xrange(1, n):
        if s[i] > k:
            return chr(ord(k) + 1) * n
    return k * n

def main():
    d = int(raw_input().strip())
    print solution(str(d))

if __name__ == '__main__':
    main()
