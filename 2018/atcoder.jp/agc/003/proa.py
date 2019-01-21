def isAbleToBack(plan):
    alphaToInt = {'E':0, 'W':1, 'N':2, 'S':3}
    count = [False]*4
    for c in plan:
        count[alphaToInt[c]] = True
    for i in xrange(4):
        if count[i] and not count[i^1]:
            return False
    return True

def main():
    plan = raw_input().strip()
    if isAbleToBack(plan):
        print 'Yes'
    else:
        print 'No'

if __name__ == '__main__':
    main()
