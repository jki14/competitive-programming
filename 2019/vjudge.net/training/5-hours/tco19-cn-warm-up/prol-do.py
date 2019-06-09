import sys

sys.stdout.write('#include <iostream>\nconstexpr int foo[] = [');

first = True

while True:
  try:
    value = int(raw_input().strip())
    if not first:
      sys.stdout.write(',')
    else:
      first = False
    sys.stdout.write('%d' % value)
  except:
    break

sys.stdout.write('];\n');
