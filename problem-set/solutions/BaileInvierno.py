T = int(raw_input())
for i in range(T):
	M, N, D = [int(x) for x in raw_input().split()]
	men = [int(x) for x in raw_input().split()]
	women = [int(x) for x in raw_input().split()]
	men = sorted(men)
	women = sorted(women)
	p, q = 0, 0
	pairs = 0
	while p < M and q < N:
		if abs(men[p]-women[q]) <= D:
			p += 1
			q += 1
			pairs += 1
		elif men[p] < women[q]:
			p += 1
		else:
			q += 1
	print "# maximo de parejas equilibradas = %i"%pairs