foo = 'const lld best[256]={'
first = True
with open('A063673.txt', 'r') as f:
    while True:
        line = f.readline()
        if not line:
            break
        x, y = [int(i) for i in line.split()]
        if not first:
            foo += ','
        else:
            first = False
        foo += str(y)+'LL'
foo += '};'
print foo
