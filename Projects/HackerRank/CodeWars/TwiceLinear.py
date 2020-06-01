def dbl_linear(n):
	#print(n)
	u = [0] * n ** 2
	u[1] = 1
	added = [1]
	#print(u)
	count = 1
	i = 0
	while count < n:
		x = added[i]
		y = 2 * x + 1
		z = 3 * x + 1
		u[x] = 1
		u[y] = 1
		u[z] = 1
		added += [y,z]
		#print('u',u)
		#print('added',added)
		count += 2
		i += 1
	count = 0
	for i in range(len(u)):
		if u[i] == 1:
			count += 1
		if count == n:
			return i 



print(dbl_linear(20))


		

















'''

def testing(actual, expected):
	assert actual == expected
	
testing(dbl_linear(10), 22)
testing(dbl_linear(20), 57)
testing(dbl_linear(30), 91)
testing(dbl_linear(50), 175)
'''