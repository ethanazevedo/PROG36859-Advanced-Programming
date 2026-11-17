# Linked List
# - data node: data and link to next node 
# - to access data, traverse from head 
# - data not stored in adjacent memory space 
# - good for operations inserting/deleting at beginning

class Node:
  def __init__(self, data):
    self.data = data
    self.link = None 

class LinkedList:
  def __init__(self):
    self.head = None 

  def insert(self, data): # add to beginning 
    node = Node(data)
    node.link = self.head 
    self.head = node 

  def append(self, data): # add to end 
    node = Node(data)
    if self.head is None: # empty
      self.head = node 
    curr = self.head 
    while curr.link is not None:
      curr = curr.link 
    curr.link = node 

  def print(self):
    print('Head->', end='')
    curr = self.head 
    while curr is not None:
      print(curr.data, end='->')
      curr = curr.link 
    print('None')

  # delete, remove, search, count, sort, insert_pos, ...

def main():
  llst1 = LinkedList()
  llst1.print()
  for n in range(1, 11):
    llst1.insert(n)
    llst1.print()
    llst1.append(n)
    llst1.print()

main()
