# OOP Basics

# VS. CPP   
# - attributes: member variables
# - methods: member functions
# - public, private, protected.
#   - "private": named __xxx
# - initializer: constructor 

import math

class Circle:
    # initializer
    def __init__(self, radius=1.0, color='black'): # required followed by optional(default)
        self.radius = radius
        self.color = color

    # getters (accessor) and  setters (mutators)
    def get_radius(self):
        return self.radius
    def get_color(self):
        return self.color
    def set_radius(self, radius):
        self.radius = radius
    def set_color(self, color):
        self.color = color

    # other methods

    def get_area(self):
        return math.pi * self.radius ** 2

    #   magic methods:
    #   - named xxxx
    #   - called implicity, to customize behavior
    #   - opterator overloading oop <, >, ==, >=
    def str(self):
        return f'Circle({self.radius}, {self.color})'

    def repr(self):
        # return f'Circle({self.radius}, {self.color})'
        return str(self)

    def eq(self, other): # for ==
        if isinstance(other, Circle):
            return self.radius == other.radius and self.color == other.color
        return False

    def lt(self, other): # for <
        if isinstance(other, Circle):
            return self.radius < other.radius
        raise TypeError('Circle can compare with another circle only')

    def ge(self, other): # for >=
        if isinstance(other, Circle):
            return self.radius >= other.radius
        raise TypeError('Circle cannot compare with other types than Circle')

#dataclass
# - decorator: @dataclass
# - auto-insert some methods: __init__, __repr__, __eq__, __lt__, __le__, __gt__, __ge__
# what is this?: A decorator that automatically generates special methods for a class

from dataclasses import dataclass
@dataclass
class Student:
    name: str
    age: int = 18
    dept: str = 'FAST'
    gpa: float = 4.0




def main():
    c1 = Circle()
    c2 = Circle(2.3, 'red')
    print(c1.get_radius(), c2.get_color())
    c1.set_radius(3.4)
    c2.set_color('green')
    print(c1.get_radius(), c2.get_color())
    print(c1.get_area(), c2.get_area())

    print(c1, c2)
    print([c1, c2])
    print(c1 == c2, c1 < c2, c1 >= c2)
    try:
        print(c1 == 'Hello', c1 < 'world', c1 > 'Python') # TypeError: Circle can compare with another circle
    except Exception as ex:
        print('something is wrong:')


    s1 = Student('Alex')
    s2 = Student('Jackie', 20, 'CS', 3.5)
    s3 = Student('John', 19, 'EE', 3.8)
    print(s1, s2, s3)
    print([s1, s2, s3])

main()