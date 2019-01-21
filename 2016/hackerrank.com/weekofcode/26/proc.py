import math

r = int(math.floor(math.sqrt(1000000000)))

ans = 0

for x in range(1, r+1):
    ans += 1000000/x

print ans
