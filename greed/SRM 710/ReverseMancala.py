arr = [int(i) for i in raw_input().split()]
while True:
    c = int(raw_input())
    if c<len(arr):
        foo = arr[c]
        arr[c] = 0
        while foo>0:
            c = (c+1)%len(arr)
            foo -= 1
            arr[c] += 1
    else:
        c -= len(arr)
        foo = 0
        while arr[c]>0:
            foo += 1
            arr[c] -= 1
            c = (c-1)%len(arr)
        arr[c] += foo
    print arr
