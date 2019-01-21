def main_entry():
    while True:
        try:
            n = int(raw_input())
        except ValueError:
            continue
        except EOFError:
            break
        x_axis = 0
        y_axis = 0
        for i in range(n*n): 
            x, y = [int(x) for x in raw_input().split()]
            x = 1<<(x-1)
            y = 1<<(y-1)
            if not x_axis&x and not y_axis&y:
                x_axis |= x
                y_axis |= y
                print i+1,
        print

if __name__ == '__main__':
    main_entry()
