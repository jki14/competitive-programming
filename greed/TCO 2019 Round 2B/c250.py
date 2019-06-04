from random import randint

foo = [str(randint(0, 99)) for i in xrange(1000)]
print(','.join(foo))
