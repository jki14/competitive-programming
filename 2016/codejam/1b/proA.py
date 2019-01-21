def GettingDigits(s):
    cheatsheet = [ ('ZERO', 'Z', 0), ('SIX', 'X', 6), ('EIGHT', 'G', 8), ('THREE', 'H', 3), ('TWO', 'W', 2), ('FOUR', 'U', 4), ('ONE', 'O', 1), ('SEVEN', 'S', 7), ('FIVE', 'F', 5), ('NINE', 'I', 9) ]
    count = [0 for i in xrange(26)]
    for c in s:
        count[ord(c) - ord('A')] += 1
    foo = [0 for i in xrange(10)]
    for row in cheatsheet:
        foo[row[2]] += count[ord(row[1]) - ord('A')]
        for c in row[0]:
            count[ord(c) - ord('A')] -= foo[row[2]]
    buff = ''
    for i in xrange(10):
        buff += chr(ord('0') + i) * foo[i]
    return buff

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        s = raw_input().strip()
        print'Case #%d: %s' % (i+1, GettingDigits(s))

if __name__ == '__main__':
    main()
