from math import sqrt, ceil, floor

def rectangle_rotation(a, b):

  diagAodd = 1 + 2 * floor( (a/2) / sqrt(2))
  diagAeven = 2 * (1 + floor( (a/2) / sqrt(2) - 0.5))

  diagBodd = 1 + 2 * floor( (b/2) / sqrt(2))
  diagBeven = 2 * (1 + floor( (b/2) / sqrt(2) - 0.5))

  return diagAeven * diagBeven + diagAodd * diagBodd

 

print(rectangle_rotation(4,2))  
print( rectangle_rotation(6,4),23)
print( rectangle_rotation(30,2),65)
print( rectangle_rotation(8,6),49)
print( rectangle_rotation(16,20),333)
