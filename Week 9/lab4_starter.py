# Note: Do NOT modify any provided code

# import
from abc import ABC, abstractmethod

# TODO: Swimmable 
class Swimmable(ABC):
    @abstractmethod
    def swim(self):
        pass

# TODO: Vehicle 
class Vehicle(ABC):
    def __init__(self, speed):
        self.speed = speed

    @abstractmethod
    def speed_up(self):
        pass

    @abstractmethod
    def slow_down(self):
        pass


# TODO: Car 
class Car(Vehicle):
    def __init__(self, speed, model):
        super().__init__(speed)
        self.model = model

    def speed_up(self):
        print("The car is speeding up")

    def slow_down(self):
        print("The car is slowing down")

# TODO: Boat 
class Boat(Vehicle, Swimmable):
    def __init__(self, speed, size):
        super().__init__(speed)
        self.size = size

    def speed_up(self):
        print("The boat is speeding up")

    def slow_down(self):
        print("The boat is slowing down")

    def swim(self):
        print("The boat is swimming")

# TODO: Animal
class Animal(ABC):
    def __init__(self, name):
        self.name = name

    @abstractmethod
    def speak(self):
        pass

    @abstractmethod
    def eat(self):
        pass

# TODO: Cat 
class Cat(Animal):
    def __init__(self, name, color):
        super().__init__(name)
        self.color = color

    def speak(self):
        print("The cat is speaking")

    def eat(self):
        print("The cat is eating")

# TODO: Fish 
class Fish(Animal, Swimmable):
    def __init__(self, name, weight):
        super().__init__(name)
        self.weight = weight

    def speak(self):
        print("The fish is speaking")

    def eat(self):
        print("The fish is eating")

    def swim(self):
        print("The fish is swimming")


# TODO: categorize_objects()
def categorize_objects(objects):
    swimmables = []
    vehicles = []
    animals = []
    
    for obj in objects:
        if isinstance(obj, Swimmable):
            swimmables.append(obj)
        if isinstance(obj, Vehicle):
            vehicles.append(obj)
        if isinstance(obj, Animal):
            animals.append(obj)
            
    return swimmables, vehicles, animals

def test_code():    
    # TODO: Create 4 objects: car, boat, cat, fish
    car = Car(120, "Volkswagen")
    boat = Boat(20, "Small")
    cat = Cat("Mickey", "White")
    fish = Fish("glup glup", 0.1)

    # TODO: Call all methods of all of the 4 objects 
    car.speed_up()
    car.slow_down()

    boat.speed_up()
    boat.slow_down()
    boat.swim()

    cat.speak()
    cat.eat()

    fish.speak()
    fish.eat()
    fish.swim()

    # TODO: Create a list containing all of the 4 objects
    obj_list = [car, boat, cat, fish]

    # TODO: Call categorize_objects using the list, print the return values
    swimmables, vehicles, animals = categorize_objects(obj_list)
    print("Swimmables:", swimmables)
    print("Vehicles:", vehicles)
    print("Animals:", animals)

    pass 

if __name__ == '__main__':
    test_code()