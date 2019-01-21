class KMP:
    pattern = None
    length = -1
    failed = None
    def __init__(self, pattern):
        self.pattern = pattern
        self.length = len(pattern)
        self.failed = [-1 for i in xrange(self.length)]
        for i in xrange(1, self.length):
            prev = self.failed[i-1]
            while prev!=-1 and pattern[prev+1]!=pattern[i]:
                prev = self.failed[prev]
            if pattern[prev+1]==pattern[i]:
                prev += 1
            self.failed[i] = prev

def minimumLen(s, t):
    kmp = KMP(t)
    offset = -1
    for c in s:
        while offset!=-1 and kmp.pattern[offset+1]!=c:
            offset = kmp.failed[offset]
        if kmp.pattern[offset+1]==c:
            offset += 1
    return len(s)+len(t)-(offset+1)

def main():
    n = int(raw_input().strip())
    s = raw_input().strip()
    t = raw_input().strip()
    print minimumLen(s, t)

if __name__ == '__main__':
    main()
