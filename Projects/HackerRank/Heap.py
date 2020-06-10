def getParentIndex(i):
	if i == 0:
		# Root 
		return 0
	return (i - 1) // 2

def getLeftChildIndex(i, n):
	left = i * 2 + 1
	if left < n:
		return left
	else:
		return None

def getRightChildIndex(i, n):
	right = (i + 1) * 2
	if right < n:
		return right
	else:
		return None

def getLargerChildIndex(i, arr):
	# Returns zero based index of larger child
	# If no children, returns None 
	n = len(arr)
	left = getLeftChildIndex(i, n)
	right = getRightChildIndex(i, n)
	#print('LargerChildIndex', left, right)

	if not left or not right:
		if not left:
			return right
		else:
			return left

	if arr[left] >= arr[right]:
		return left
	else:
		return right 

def swap(i1, i2, arr):
	temp = arr[i1]
	arr[i1] = arr[i2]
	arr[i2] = temp

def heapifyMax(arr):
	n = len(arr)
	for i in reversed(range(0, n)):
		print('i:', i, 'num', arr[i], 'arr:', arr)

		# Check if parent smaller than children 
		parentIndex = getParentIndex(i)
		larger = getLargerChildIndex(parentIndex, arr)
		while larger and arr[larger] > arr[parentIndex]:
			print('Swap arr[', parentIndex, ']:', arr[parentIndex], 'arr[', larger, ']:', arr[larger])
			swap(parentIndex, larger, arr)
			parentIndex = getParentIndex(parentIndex)
			larger = getLargerChildIndex(parentIndex, arr)
	return arr



l = [5,10,15,20,25,30,35]


#print(getParent(getLargerChild(3, l)))
print(l)
print(heapifyMax(l))

