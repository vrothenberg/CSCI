import itertools

def question2a():
	print("\nQuestion 2a\n")
	l = []

	for i in itertools.product('ACGT', repeat=4):

		if (i[0] == i[-1] and i[1] not in 'AC'):
			s = "".join(i)
			l.append(s)
			print(s)

	print(len(l))


def question2b():
	print("\nQuestion 2b\n")

	l = []

	for i in itertools.product('ACGT', repeat=4):

		if ((i.count('A') == 2 * i.count('G')) and i.count('T') <= 1):
			s = "".join(i)
			l.append(s)
			print(s)

	print(len(l))


question2a()
question2b()