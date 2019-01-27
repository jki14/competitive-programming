def main():
  n, a, b = [int(i) for i in raw_input().strip().split()]
  print('%d %d' % (min(a, b), max(a + b - n, 0)))

if __name__ == '__main__':
  main()
