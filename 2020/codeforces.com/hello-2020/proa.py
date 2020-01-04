import sys

def solution(a, b, req):
    n, m = len(a), len(b)
    for y in req:
        sys.stdout.write('%s\n' % (a[(y  - 1) % n] + b[(y - 1) % m]))

def main():
    while True:
        try:
            n, m = [int(i) for i in input().strip().split()]
            a = [i for i in input().strip().split()]
            b = [i for i in input().strip().split()]
            q = int(input().strip())
            req = [int(input().strip()) for i in range(q)] 
            solution(a, b, req)
        except EOFError:
            break

if __name__ == '__main__':
    main()
