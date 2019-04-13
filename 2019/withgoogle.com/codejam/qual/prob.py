def find(sa, c):
  foo = 0
  for i in xrange(len(sa) - 1):
    if c == sa[i]:
      foo += 1
      if c == sa[i + 1]:
        return foo
  return None

def solution(sa, n):
  flip = {'E':'S', 'S':'E'}
  sb = ['?' for i in xrange(n + n - 2)]
  if sa[0] != sa[-1]:
    sb[0] = flip[sa[0]]
    for i in xrange(1, n - 1):
      sb[i] = sb[0]
    sb[n - 1] = sa[0]
    for i in xrange(n, n + n - 2):
      sb[i] = sb[n - 1]
  else:
    sb[0] = flip[sa[0]]
    p = find(sa, sb[0])
    for i in xrange(1, p):
      sb[i] = sb[0]
    for i in xrange(p, p + n - 1):
      sb[i] = sa[0]
    for i in xrange(p + n - 1, n + n - 2):
      sb[i] = sb[0]
  return ''.join(sb)

def main():
  nc = int(raw_input().strip())
  for i in xrange(nc):
    n = int(raw_input().strip())
    sa = raw_input().strip()
    sb = solution(sa, n)
    print('Case #%d: %s' % (i + 1, sb))

if __name__ == '__main__':
  main()
