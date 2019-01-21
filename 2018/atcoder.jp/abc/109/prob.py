def solution(w):
    pre = { }
    cur = w[0]
    pre[cur] = True
    for i in xrange(1, len(w)):
        if cur[-1] != w[i][0]:
            return False
        cur = w[i]
        if cur in pre:
            return False
        pre[cur] = True
    return True

def main():
    n = int(raw_input().strip())
    a = [raw_input().strip() for i in xrange(n)]
    if solution(a):
        print 'Yes'
    else:
        print 'No'

if __name__ == '__main__':
    main()
