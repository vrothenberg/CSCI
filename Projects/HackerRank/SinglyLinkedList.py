#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)

def printList(node):
    while node:
        print(str(node.data))
        node = node.next


# Complete the insertNodeAtTail function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#

'''
def insertNodeAtTail(head, data):
  if head == None:
    head = SinglyLinkedListNode(data)
  else:
    if head.next == None:
      head.next = SinglyLinkedListNode(data)
    else:
      insertNodeAtTail(head.next, data) # Max Recursion Depth!
  return head
'''

def insertNodeAtTail(list, data):
    #print("Begin")
    head = list.head

    node = head
    while True:
        if head == None:
            print("head == None")
            head = SinglyLinkedListNode(data)
            print(head.data)
            return head
        if node.next == None:
            node.next = SinglyLinkedListNode(data)
            break
        else:
            node = node.next
    #print(head.data)
    return head

'''
if __name__ == '__main__':
    fptr = open('output.txt', 'w')
    infile = open('input.txt', 'r')

    llist_count = int(infile.readline())

    llist = SinglyLinkedList()

    for i in range(llist_count):
        llist_item = int(infile.readline())
        llist_head = insertNodeAtTail(llist.head, llist_item)
        llist.head = llist_head

    print_singly_linked_list(llist.head, '\n', fptr)
    fptr.write('\n')

    fptr.close()
'''

llist = SinglyLinkedList()
#llist.head = SinglyLinkedListNode(0)
insertNodeAtTail(llist, 1)
insertNodeAtTail(llist, 2)
insertNodeAtTail(llist, 3)
printList(llist.head)
