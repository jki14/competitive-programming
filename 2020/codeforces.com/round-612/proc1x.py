import sys

def main():
    a = sys.argv[1]
    l = len(a)
    for i in range(l):
        for j in range(i, l):
            sys.stdout.write('%s\n' % a[i : j + 1])

if __name__ == '__main__':
    main()
