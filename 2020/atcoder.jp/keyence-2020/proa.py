import sys

def main():
    n = int(raw_input().strip())
    m = int(raw_input().strip())
    k = int(raw_input().strip())
    p = max(n, m)
    sys.stdout.write('%d\n' % ((k + p - 1) / p))

if __name__ == '__main__':
    main()
