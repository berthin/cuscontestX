T = int(raw_input())
for iT in xrange(1, T + 1):
  numbers = map(int, raw_input().split(' '))
  print "Caso #%d: %d" % (iT, sum(numbers))
