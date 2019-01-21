def SherlockAndParentheses(n, m):
    #TODO: check if n and m are valid
    k = min(n, m)
    return (k + 1) * k / 2

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        n, m = [int(j) for j in raw_input().strip().split()]
        print('Case #%d: %d' % (i + 1, SherlockAndParentheses(n, m)))

if __name__ == '__main__':
    main()
