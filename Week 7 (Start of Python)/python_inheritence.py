# 1. Class attributes & class methods
# - like static in CPP
# - instance attributes & methods: self.xxx
# - class attributes & methods: belongs to class, shared by all instances
# - how:
#      - class attributes: outside and method
#   - class methods: @classmethod decorator, cls.xxx

class Employee:
    count = 0
    position = []
    employees = []
    def __init__(self, eid, name, position='developer', salary=1000.0):
        self.eid, self.name, self.position, self.salary = eid, name, position, salary
        Employee.count += 1
        if position not in Employee.position:
            Employee.position.append(position)
        Employee.employees.append(self)

    def __str__(self):
        return f'Employee: {self.eid}, {self.name}, {self.position}, {self.salary:.2f}\n'

    def __repr__(self):
        return str(self)

    @classmethod
    def get_employee_count(cls):
        return cls.count

    @classmethod
    def get_employee_positions(cls):
        return cls.positions

import random

def main():
    employees = [Employee(
        eid=1000 + i,
        name=''.join(random.choices('abcdefghijklmnopqrstuvwxyz', k=random.randint(3, 10))).title(),
        position=random.choice(['developer', 'tester', 'engineer', 'CEO', 'CTO']),
        salary=random.uniform(1000.0, 9999.99)
    ) for i in range(20)]
    print(employees)

    # call class method
    print('hi')
    print(Employee.get_employee_count())
    e1 = Employee(999, 'Jack', 'Director', 3456.78)
    print(Employee.get_employee_positions())

if __name__ == '__main__':
    main()


# 2. Inheritance & polymorphism
# - IS-A
# - superclass: base class in Cpp
# - subclass: derived class in Cpp
# - overriding: method re-defining in subclass

#superclass
class Vehicle:
    def __init__(self, model, speed=0):
        self.model, self.speed = model, speed
    def __str__(self):
        pass

    def print_info(self):
        print(f'Vehicle: {self.model}, Speed: {self.speed}')

#subclass
class Car(Vehicle): #Subclass(Superclass) - inheritance
    def __init__(self, model, speed, price):
        super().__init__(model, speed)
        self.price = price 

    def print_info(self): #overriding 
        super().print_info()
        print(f'\tCar: {self.price}')

    def show(self):
        print(f'Car {self.model} is running at {self.speed}, it costs {self.price}')

def print_vehicles(vehicles):
    for v in vehicles:
        v.print_info()
        print('-' * 20)


import random
def main():
    v1 = Vehicle('BMW', 0.0)
    v1.print_info()
    c1 = Car('Benz', 100.0, 3344.55)
    c1.print_info
    c1.show()

    vehicles = [
        Vehicle(random.choice(['BMW', 'Benz', 'Toyota', 'Honda', 'Ford']),
                random.uniform(0.0, 100.0))
                if random.randint(0, 1) == 0 else
                Car(random.choice(['BMW', 'Benz', 'Toyota', 'Honda', 'Ford']),
                        random.uniform(0.0, 100.0),
                        random.uniform(0.0, 999999.99)) for i in range(15)
    ]
    print_vehicles(vehicles)

    print('-' * 40)