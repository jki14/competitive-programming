# -*- coding: ascii -*-

def process():
    a = raw_input().strip()
    if len(a)>=2 and a[-2:]=='ic':
        if len(a)>=5 and a[:5]=='hydro':
            print 'non-metal acid'
        else:
            print 'polyatomic acid'
    else:
        print 'not an acid'

def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        process()

if __name__ == '__main__':
    main()
