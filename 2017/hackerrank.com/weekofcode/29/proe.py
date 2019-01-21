import decimal

decimal.getcontext().prec = 50

pi = decimal.Decimal(31415926535897932384626433832795028841971693993751) / 10**49

def getNumerator(denominator):
    return int(denominator * pi + decimal.Decimal(0.5))

def getDistanceToPi(denominator):
    numerator = getNumerator(denominator)
    return abs(decimal.Decimal(numerator) / denominator - pi)

def getPiContinuedFraction(size): # also https://oeis.org/A001203
    f = []
    p = pi - 3
    for _ in range(size):
        p = 1 / p
        f.append(int(p))
        p -= int(p)
    return f

def getDistancesToTheNextMinimum(piContinuedFractionSize):
    distances = [1]
    for item in getPiContinuedFraction(piContinuedFractionSize):
        if len(distances) == 1:
            prev = 1
        else:
            prev = distances[-2]
        for _ in range(item):
            distances.append(distances[-1] + prev)
    return distances

def getBestApproximation(min, max):
    cur = min
    minDist = getDistanceToPi(cur)
    steps = getDistancesToTheNextMinimum(27)
    print steps
    while True:
        for step in steps:
            if cur + step > max:
                return str(getNumerator(cur)) + "/" + str(cur)
            dist = getDistanceToPi(cur + step)
            if dist < minDist:
                minDist = dist
                cur += step
                break
    
min, max = map(int, raw_input().split())
print(getBestApproximation(min, max))
