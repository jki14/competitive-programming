from sys import stdout

def solution(s):
    #todo: check if s is valid
    f = [0 for i in xrange(26)]
    for c in s:
        if 'a' <= c and c <= 'z':
            f[ord(c) - ord('a')] += 1
        elif 'A' <= c and c <= 'Z':
            f[ord(c) - ord('A')] += 1
    f = sorted(f)
    return sum([f[i] * (i + 1) for i in xrange(26)])

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        s = raw_input().strip()
        stdout.write('Case #%d: %d\n' % (case_id, solution(s)))
        stdout.flush()

if __name__ == '__main__':
    main()
