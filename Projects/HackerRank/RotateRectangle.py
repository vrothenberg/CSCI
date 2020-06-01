from math import sqrt, ceil, floor

def rectangle_rotation(a, b):

  def bottom(x):
  	return -x - a/2 * sqrt(2)

  def left(x):
  	return x + b/2 * sqrt(2)

  def right(x):
  	return x - b/2 * sqrt(2)

  def top(x):
  	return -x + a/2 * sqrt(2)

  def inside(x,y):
  	if y < top(x) and y < left(x) and y > right(x) and y > bottom(x):
  		return True
  	return False

  def addNeighbors(x,y):
  	# Looks right, left and down 
	  if (x+1,y) not in explored:
	  	toExplore.append((x+1,y))
	  if (x-1,y) not in explored:
	  	toExplore.append((x-1,y))
	  if (x,y-1) not in explored:
	  	toExplore.append((x,y-1))

  
  lowX = -0.25 * sqrt(2) * (a - b) 
  lowY = bottom(lowX)

  leftX = -0.25 * sqrt(2) * (a + b)
  leftY = bottom(leftX)

  rightX = 0.25 * sqrt(2) * (a + b)
  rightY = top(rightX)

  topX = 0.25 * sqrt(2) * (a - b)
  topY = top(topX)

  #print('Low (x,y):', lowX, lowY)
  #print('Left (x,y):', leftX, leftY)
  #print('Right (x,y):', rightX, rightY)
  #print('Top (x,y):', topX, topY)

  lowY_int = ceil(lowY)
  leftX_int = ceil(leftX)
  rightX_int = floor(rightX)
  topX_int = floor(topX)
  topY_int = floor(topY)


  #print('Low Y', lowY_int)
  #print('Left X', leftX_int)
  #print('Right X', rightX_int)
  #print('Top Y', topY_int)


  deltaY = topY_int - lowY_int + 1
  deltaX = rightX_int - leftX_int + 1

  #print('Delta X', deltaX)
  #print('Delta Y', deltaY)

  count = 0

  # Start at Top 
  # Work left until not inside
 
  x,y = topX_int, topY_int
  explored = {}
  toExplore = []

  if inside(x,y):
  	count += 1
  addNeighbors(x,y)
  explored[(x,y)] = 1
  	
  while toExplore:
  	# Left
  	x,y = toExplore.pop()
  	explored[(x,y)] = 1
  	if inside(x,y):
  		addNeighbors(x,y)
  		count += 1

  return count 
  
print( rectangle_rotation(6,4),23)
print( rectangle_rotation(30,2),65)
print( rectangle_rotation(8,6),49)
print( rectangle_rotation(16,20),333)
