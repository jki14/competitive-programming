import numpy
import math

foo = numpy.ones(1000001)
dust = 0

e = int(math.sqrt(1000000)+1.)

foo[0] = 0
foo[1] = 0

i = 4
while i <= 1000000:
    foo[i] = 0
    i += 2

i = 3
while i < e:
    if foo[i] == 0:
        i += 2
        continue
    d = i*2
    j = i*i
    while j <= 1000000:
        if foo[j] == 0:
            dust += 1
        foo[j] = 0
        j += d
    i += 2

print dust
