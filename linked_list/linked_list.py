#!/usr/bin/env python3

"""
implementation of a singly-linked list

operations:
    add_front() adds a new node to the front of the list
    add_back() adds a new node to the back of the list
    add_at_index() adds a new node at a given index
    print_list() prints every node in the list
    length() returns the number of nodes in the list
"""

class LinkedList:

    def __init__(self):
        self.head = Node(None, None, None)

    def add_front(self, new_node):
        """adds a new Node to the front of the list"""
        new_node.next = self.head
        self.head = new_node

    def print_list(self):
        """prints every node in the list"""
        temp = self.head
        while temp.next is not None:
            print('{} {} - {} points'.format(
                temp.first_name, temp.last_name, temp.points))
            temp = temp.next

class Node:

    def __init__(self, first_name, last_name, points):
        self.first_name = first_name
        self.last_name = last_name
        self.points = points
        self.next = None

# create a linked list
ll = LinkedList()

# create some nodes
mike = Node('Michael', 'Jordan', 68)
kobe = Node('Kobe', 'Bryant', 71)

# add them to the list
ll.add_front(mike)
ll.add_front(kobe)

# print the list
ll.print_list()
