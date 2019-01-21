from sys import stdout

class DigitNumber:

    def __init__(self, number):
        self.number = number
    
    def get_digit(self, base):
        return self.number / base % 10
    
    def on_oneswap(self, basex, basey):
        return self.number - (self.get_digit(basex) * basex + self.get_digit(basey) * basey) + (self.get_digit(basey) * basex + self.get_digit(basex) * basey)
    

def solution(original):
    #todo: check if original is valid
    a = DigitNumber(original)
    #smallest
    smallest = a.number
    regular, nonzero = 1, 0
    k = 1
    while a.number >= k:
        digit = a.get_digit(k)
        if digit < a.get_digit(regular):
            regular = k
        if digit != 0 and (nonzero == 0 or digit < a.get_digit(nonzero)):
            nonzero = k
        if a.number >= k * 10:
            if digit > a.get_digit(regular):
                smallest = a.on_oneswap(k, regular)
        else:
            if nonzero != 0 and digit > a.get_digit(nonzero):
                smallest = a.on_oneswap(k, nonzero)
        k *= 10
    #largest
    largest = a.number
    regular = 1
    k = 10
    while a.number >= k:
        digit = a.get_digit(k)
        if digit > a.get_digit(regular):
            regular = k
        if digit < a.get_digit(regular):
            largest = a.on_oneswap(k, regular)
        k *= 10
    return smallest, largest

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        original = int(raw_input().strip())
        foo = solution(original)
        stdout.write('Case #%d: %d %d\n' % (case_id, foo[0], foo[1]))
        stdout.flush()

if __name__ == '__main__':
    main()
