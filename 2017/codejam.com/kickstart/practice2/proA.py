def DiwaliLightings(pattern, left, right) :
    #TODO: check if parameters are valid
    lenpat = len(pattern)
    prefix = [0 for i in xrange(lenpat)]
    suffix = [0 for i in xrange(lenpat)]
    if pattern[0] == 'B':
        prefix[0] = 1
    for i in xrange(1, lenpat):
        if pattern[i] == 'B':
            prefix[i] = prefix[i - 1] + 1
        else:
            prefix[i] = prefix[i - 1]
    if pattern[-1] == 'B':
        suffix[-1] = 1
    for i in xrange(2, lenpat+1):
        if pattern[-i] == 'B':
            suffix[-i] = suffix[-i + 1] + 1
        else:
            suffix[-i] = suffix[-i + 1]
    foo = 0
    foo += suffix[left % lenpat]
    foo += prefix[right % lenpat]
    left_round = (left + lenpat) / lenpat
    right_round = right / lenpat
    foo += (right_round - left_round) * prefix[-1]
    return foo

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        pattern = raw_input().strip()
        left, right = [int(j) for j in raw_input().strip().split()]
        print('Case #%d: %d'%(i + 1, DiwaliLightings(pattern, left - 1, right - 1)))

if __name__ == '__main__':
    main()
