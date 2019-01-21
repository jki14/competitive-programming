def solution(a):
    #todo: check if a is valid
    return sum(a) - len(a)
 
def main():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    print solution(a)
 
if __name__ == '__main__':
    main()