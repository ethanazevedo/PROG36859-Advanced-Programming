# 1. Multiple inheritance, diamond problem, MRO
# - multi-level inheritance: hierarchy, root = class object
# - mutliple inheritance: one subclass can inherite from multiple superclasses
# - diamond problem: multiple superclasses shared common ancester
# - MRO: method-resolution-order
# - Note: in practice try to avoid multiple inheritance
#   - In Cpp: virtual inheritance

from dataclasses import dataclass 
# superclass 1
@dataclass
class Audio:
  filetype: str 
  length: int 

# superclass 2
@dataclass 
class Book:
  isbn: int 
  title: str 
  author: str 
  price: float

# subclass
class AudioBook(Audio, Book):
  def __init__(self, filetype, length, isbn, title, author, price):
    # way 1: initialize individually
    # way 2: using super()
    # way 3: using class name (explicitly)
    Audio.__init__(self, filetype, length)
    Book.__init__(self, isbn, title, author, price)

# 2. ABC, interface
# - concrete class: instantiable (can create objects)
# - abstract class: not instantiable (cannot create object), too general
#   - abstract base class: serving as superclass
#     - inherite from ABC
#     - contains some abstract methods (pure virtual functions in Cpp)
#     - may have init and concrete methods
#   - interface: contains abstract methods only

from abc import ABC, abstractmethod 
import math 

class Shape(ABC):
  def __init__(self, line):
    self.line = line 

  @abstractmethod
  def area(self):
    pass 

class Circle(Shape):
  def __init__(self, line, radius):
    super().__init__(line)
    self.radius = radius 

  def area(self):
    return math.pi * self.radius ** 2

class Paintable(ABC):
  @abstractmethod
  def paint(self, color):
    pass 

class ColorCircle(Circle, Paintable):
  def __init__(self, line, radius, color):
    super().__init__(line, radius)
    self.color = color 

  def paint(self, color):
    print(f'Painting the circle in {color}')
    self.color = color 
    
def main():
  ab1 = AudioBook('mp3', '30', '9051234567', 'The Matrix I', 'Prof. Sun', 123.45)
  print(ab1.filetype, ab1.title, ab1.price)
  print(AudioBook.__mro__)

  cc1 = ColorCircle('solid', 3.3, 'red')
  print(cc1.area())
  cc1.paint('green')
  print(cc1.color)

  print(isinstance(cc1, ColorCircle), isinstance(cc1, Circle), 
        isinstance(cc1, Shape), isinstance(cc1, Paintable))
  print(issubclass(ColorCircle, Circle), issubclass(ColorCircle, Shape), 
        issubclass(ColorCircle, Paintable))

main()

