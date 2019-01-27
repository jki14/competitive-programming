def main():
  n = int(raw_input().strip())
  a = [raw_input().strip() for i in xrange(3)]
  foo = 0
  for i in xrange(n):
    bucket = { }
    for s in a:
      bucket[s[i]] = True
    foo += len(bucket) - 1
  print(foo)

if __name__ == '__main__':
  main()
