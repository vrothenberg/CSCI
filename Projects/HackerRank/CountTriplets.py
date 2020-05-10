#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countTriplets function below.
def countTriplets(arr, r):
  arr.sort()
  numTriplets = 0
  hTable = {}
  for i, x in enumerate(arr):
    if x not in hTable.keys():
      hTable[x] = {}
    hTable[x][i] = len(hTable[x]) + 1

  for i, x in enumerate(arr):
    second = r*x
    if r == 1 and len(hTable[x]) >= 3:
      #secondLayer =
      #secondChoices = len(hTable[x]) - hTable[x][i] - 2
      #thirdChoices = len(hTable[x]) - hTable[x][i] - 3
      num = len(hTable[x]) - hTable[x][i] - 1
      sumNum = num * (num + 1) / 2
      numTriplets += int(sumNum)


    elif second in hTable.keys():
      # 0 1 2 3 4
      # 1 1 1 1 1
      # i = 2
      secondChoices = len(hTable[second])
      third = r*second
      if third in hTable.keys():
        thirdChoices = len(hTable[third])
        numTriplets += secondChoices * thirdChoices
  return numTriplets





if __name__ == '__main__':
    fptr = open('output.txt', 'w')

    infile = open('input2.txt', 'r')

    nr = infile.readline().rstrip().split()

    n = int(nr[0])

    r = int(nr[1])

    arr= list(map(int, infile.readline().rstrip().split()))

    infile.close()

    ans = countTriplets(arr, r)

    fptr.write(str(ans) + '\n')

    fptr.close()
