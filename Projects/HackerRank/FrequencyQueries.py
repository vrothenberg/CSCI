#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the freqQuery function below.
def freqQuery(queries):
  d = {}
  output = []
  for q in queries:
    op = q[0]
    val = q[1]
    if op == 1:
      # Insert
      if val not in d.keys():
        d[val] = 1
      else:
        d[val] += 1
    elif op == 2:
      # Delete one occurrence
      if val in d.keys() and d[val] != 0:
        d[val] -= 1
    elif op == 3:
      if val in d.values() and val >= 0:
        output.append(1)
      else:
        output.append(0)
  return output





if __name__ == '__main__':
    fptr = open('output.txt', 'w')
    input = open('input08.txt', 'r')

    q = int(input.readline().strip())

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input.readline().rstrip().split())))

    ans = freqQuery(queries)

    fptr.write('\n'.join(map(str, ans)))
    fptr.write('\n')

    fptr.close()
