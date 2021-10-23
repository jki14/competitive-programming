from sys import stdout
 
 
def calc(n):
    return 8 if n >= 212 else (6 if n >= 126 else 4)
 
 
def solution(n):
    stdout.write('%d\n' % calc(n))
 
 
def main():
    while True:
        try:
            n = int(raw_input().strip())
            solution(n)
        except EOFError:
            break
        except ValueError:
            continue
 
 
if __name__ == '__main__':
    main()
