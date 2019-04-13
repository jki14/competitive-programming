def solution(si):
  n = len(si)
  x = ['0' for i in xrange(n)]
  y = [c for c in si]
  for i in xrange(n):
    if y[i] == '4':
      y[i] = '2'
      x[i] = '2'
  return ''.join(x).lstrip('0'), ''.join(y)

def main():
  nc = int(raw_input().strip())
  for i in xrange(nc):
    si = raw_input().strip()
    x, y = solution(si)
    print('Case #%d: %s %s' % (i + 1, x, y))

if __name__ == '__main__':
  main()
