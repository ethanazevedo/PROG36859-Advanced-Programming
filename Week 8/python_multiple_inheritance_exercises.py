# Python Multiple Inheritance - Exercises


# Exercise: 
#   - write an interface Playable(ABC, play())
#   - write an abstract class Animal(ABC, name, speak())
#   - write two concrete subclasses: Cat(color) and Dog(blood). Dog also implements Playable
#   - write an abstract class Media(ABC, format, publish())
#   - write two concrete subclasses: Newspaper(pages) and Video(title). Video also implements Playable 
#   - write a function that takes a list of objects, returns three lists: playables, animals, medias
#   - write a tester that tests all classes and the function above
#   - draw a UML diagram to show the relationship of the classes
from abc import ABC, abstractmethod

