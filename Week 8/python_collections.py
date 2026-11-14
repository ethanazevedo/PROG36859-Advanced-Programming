# Built-in data structures (collections/contains)
# - Lists, tuples, dictionaries, sets 

def about_lists():
  lst = [5, 2, 3, 1, 4, 7, 6, 5, 3]
  print(len(lst), lst[0], lst[-1], lst[:len(lst) // 2], lst[::3])
  print(min(lst), max(lst), sum(lst))
  print(lst + [4, 6, 3, 5, 2], lst * 3, lst.extend([43, 21, 15]))
  lst.append(10)
  lst.insert(0, 123)
  lst[len(lst) // 2] = 3344
  lst.remove(4) # 4 is value
  lst.pop(0) # 0 is index
  print(lst.index(43), lst.count(5))
  lst.sort()
  print(lst)
  lst.reverse()
  print(lst)
  # comprehension
  # - [] -> for -> if -> append
  lst1 = [n + 1000 for n in lst]
  lst2 = [n * 2 for n in lst if n % 2 == 1]
  print(lst1, lst2)
  colors = ['red', 'black', 'yellow', 'green', 'blue']
  cap_colors = [c.upper() for c in colors]
  print(cap_colors)

def about_sets():
  # unique values, unordered
  s1 = {5, 3, 2, 4, 6, 8, 7}
  print(len(s1), min(s1), max(s1), sum(s1), 1 in s1, 33 not in s1)
  s1.add(9)
  print(s1.pop()) # arbitrary 
  s1.remove(6) # if value is not in set, get an error
  s1.discard(7) # no error 
  s1.update({11, 22, 33, 44, 3, 4, 5})
  print(s1)
  lst = [1, 1, 2, 3, 2, 1, 4, 5, 4, 3]
  lst1 = list(set(lst))
  print(lst1)
  # |(union), &(intersection), -(difference), ^(symmetric difference)
  s1, s2 = {1, 2, 3, 4, 5}, {3, 4, 5, 6, 7}
  print(s1 | s2, s1 & s2, s1 - s2, s1 ^ s2)
  # <(proper subset), <=(subset), >(proper superset), >=(superset)
  print(s1 < s2, s1 <= s2, s1 > s2, s1 >= s2)

def about_dict():
  # key:value pairs
  # - key unique, immutable
  d1 = {'a': 123, 'b': 456, 'c': 567}
  print(len(d1), 'a' in d1, 'd' not in d1, d1['a'])
  print(d1.get('a'), d1.get('xyz', 'xyz does not exist'))
  d1.update({'d': 11, 'e': 22, 'f': 33})
  d1 |= {'g': 12, 'h': 23} # merge 
  d1['h'] = 232323 # updating
  d1['xyz'] = 3344 # adding
  print(d1)
  d1.pop('xyz', None)
  # After Python 3.7, dict is order
  d1.popitem() # remove the last 

  for k in d1: print(k, ':', d1[k])
  for k in d1.keys(): print(k, ':', d1[k])
  for v in d1.values(): print(v) 
  for item in d1.items(): print(item[0], ':', item[1])
  for k, v in d1.items(): print(k, ':', v)

  # dict comprehension
  print(d1)
  d2 = {k:v*2 for k, v in d1.items()}
  d3 = {k:v for k, v in d1.items() if v % 2 == 0} 
  no = [100, 101, 102]
  names = ['Alex', 'Balex', 'Calex']
  id_name = {no[i]: names[i] for i in range(len(no))}
  print(d2, d3, id_name)

phones = [
  {
    'model': 'iPhone 17 Pro',
    'memory': [128, 256],
    'color': {'red', 'green'},
    'price': {
        (128, 'red'): 123.45,
        (128, 'green'): 124.56,
        (256, 'red'): 211.34,
        (256, 'green'): 213.45
    }
    # amount for combination of (memory, color)
  },
]

# write a program to create a phones list by reading data from the user
# - searching, updating, deleting
  
def main():
  about_lists()
  about_sets()
  about_dict()

main()
