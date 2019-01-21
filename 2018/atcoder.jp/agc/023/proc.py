def next_permutation(arr):
    for k in xrange(len(arr)-2, -1, -1):
        if arr[k]<arr[k+1]:
            i = len(arr)-1
            while arr[i]<=arr[k]:
                i -= 1
            arr[k], arr[i] = arr[i], arr[k]
            arr[k+1:] = arr[k+1:][::-1]
            return True
    return False

def main():
    while True:
        n = int(raw_input())
        arr = [i for i in xrange(n-1)]
        foo = 0
        while True:
            s = set()
            for c in arr:
                s.add(c)
                s.add(c+1)
                foo += 1
                if len(s)==n:
                    break
            if not next_permutation(arr):
                break
        print foo

if __name__ == '__main__':
    main()
