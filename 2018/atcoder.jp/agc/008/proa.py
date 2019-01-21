def minimumPress(x, y):
    foo = 0
    if abs(x) < abs(y):
        if x < 0:
            foo += 1
        foo += abs(y) - abs(x)
        x = abs(y)
    elif abs(x) > abs(y):
        if x > 0:
            foo += 1
        foo += abs(x) - abs(y)
        x = -abs(y)
    if x!=y:
        foo += 1
    return foo

def main():
    x, y = [int(i) for i in raw_input().strip().split()]
    print minimumPress(x, y)

if __name__ == '__main__':
    main()
