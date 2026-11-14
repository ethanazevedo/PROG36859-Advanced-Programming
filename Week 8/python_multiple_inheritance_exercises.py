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

class Playable(ABC):
    @abstractmethod
    def play(self):
        pass

class Animal(ABC):
    def __init__(self, name):
        self.name = name
    
    @abstractmethod
    def speak(self):
        pass


#concrete class
class Cat(Animal):
    def __init__(self, name, color):
        super().__init__(name)
        self.color = color

    def speak(self):
        return(f"Mreowwwwwwwww")

#concrete class
class Dog(Playable, Animal):
    def __init__(self, name, blood):
        super().__init__(name)
        self.blood = blood

    def play(self):
        return(f"Dog playing something...")

    def speak(self):
        return(f"WOOF WOOF")




class Media(ABC):
    def __init__(self, format):
        self.format = format

    @abstractmethod
    def publish(self):
        pass


#concrete class
class Newspaper(Media):
    def __init__(self, format, pages):
        super().__init__(format)
        self.pages = pages

    def publish(self):
        return(f"Publishing paper...")

#concrete class
class Video(Playable, Media):
    def __init__(self, format, title):
        super().__init__(format)
        self.title = title

    def play(self):
        return(f"Playing media...")

    def publish(self):
        return(f"Publishing paper...")


def sort_objects(objects):

        playables = []
        animals = []
        medias = []

        for obj in objects:
            if isinstance(obj, Playable):
                playables.append(obj)

            if isinstance(obj, Animal):
                animals.append(obj)

            if isinstance(obj, Media):
                medias.append(obj)

        return playables, animals, medias


def main():

    objects = []

    objects.append(Cat("Mickey", "White/black"))
    objects.append(Dog("Joey", "Labradore"))
    objects.append(Newspaper("Physical Copy", "24"))
    objects.append(Video("Mp4", "Jackies goon tape 1"))


    playables, animals, medias = sort_objects(objects)

    #display results
    print(f"\n--- PLAYABLES ---")
    for obj in playables:
        print(type(obj).__name__)

    print(f"\n--- ANIMALS ---")
    for obj in animals:
            print(obj.name)

    print(f"\n--- MEDIAS ---")
    for obj in medias:
            print(type(obj).__name__)



if __name__ == "__main__":
    main()





   
