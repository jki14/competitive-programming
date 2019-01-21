import numpy

foo = numpy.zeros(1000001)
til = 0
dust = 0

for i in range(2, 1000001):
    if foo[i] == 0:
        foo[til] = i
        til += 1
    j = 0
    while j<til and foo[j]<=1000000/i:
        if foo[foo[j]*i] == 1:
            dust += 1
        foo[foo[j]*i] = 1
        if i%foo[j] == 0:
            break
        j += 1

print dust
