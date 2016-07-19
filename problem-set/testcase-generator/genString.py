import sys
from random import randint

if len(sys.argv) == 3:
    testinfile = open(sys.argv[1], 'w')
    testoutfile = open(sys.argv[2], 'w')
else:
    print 'the program received one parameter'
    print './program <test.in> <test.out>'

T = 100
testinfile.write(str(T) + '\n')
max_chrs = 0
with open('text.in', 'r') as text:
    words = []
    for iT in range(T):
        n_words = randint(1, 150)
        while len(words) < n_words:
            for line in text:
                words += [x.lower() for x in line.split() if x.isalpha()]

        tmp = words[:n_words]
        sentence = ' '.join(tmp)
        testoutfile.write(sentence[:1].upper() + sentence[1:] + '.\n')
        tmp.reverse()
        sentence = ' '.join(tmp)
        testinfile.write(sentence[:1].upper() + sentence[1:] + '.\n')
        max_chrs = max(max_chrs, len(sentence) + 1)

        words = words[n_words:]
        print 'Case: ',iT


print 'max len sentence', max_chrs
