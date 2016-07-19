T = int(raw_input())
for i in xrange(T):
    words = raw_input()[:-1].lower().split(' ')
    words.reverse()
    sentence = ' '.join(words)
    print sentence[:1].upper() + sentence[1:] + '.'

