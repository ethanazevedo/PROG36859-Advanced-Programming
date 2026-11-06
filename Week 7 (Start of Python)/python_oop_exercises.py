# Python OOP - Exercises

# Exercise 1: Read the provided test code, write the two classes accordingly.

# TODO: Task class
class Task:
    def __init__(self, name, difficulty):
            self.name = name
            self.difficulty = difficulty
            self.done = False
    
    def __str__(self):
        return f"Task: {self.name}\n\tDifficulty: {self.difficulty}\n\tDone: {self.done}"
    

# TODO: SuperHero class
class SuperHero:
    def __init__(self, name, strength, skills):
        self.name = name
        self.strength = strength
        self.skills = skills
        self.tasks = []
        
    def assign_task(self, task):
         self.tasks.append(task.name)

    def complete_task(self, task):
         task.done = True

    def __str__(self):
        return f"SuperHero: {self.name}\n\tStrength: {self.strength}\n\tSkills: {self.skills}\n\tTasks: {self.tasks}"

# =============================================================================

def test():
    print('==== TODO#1/4 ====')
    """
    TODO1/4
    Write a Task class so that when running the test code below, the
          following output will be produced:
    Task: Save the world
            Difficulty: 7.3
            Done: False
    Task: Learn Python
            Difficulty: 8.7
            Done: False
    """
    task1 = Task(name='Save the world', difficulty='7.3')
    task2 = Task(name='Learn Python', difficulty='8.7')
    print(task1)
    print(task2)

    print('\n==== TODO#2/4 ====')
    """
    TODO2/4
    Write a SuperHero class so that when running the test code below, the 
          following output will be produced:
    SuperHero: Spiderman
            Strength: 8.7
            Skills: ['time travel', 'fly', 'joking', 'eat pizza']
    """
    hero1 = SuperHero(name='Spiderman', strength='8.7', 
        skills=['time travel', 'fly', 'joking', 'eat pizza'])
    print(hero1)

    print('\n==== TODO#3/4 ====')
    """
    TODO3/4
    Add code to SuperHero class so that when running the test code
          below, the following output will be produced:
    SuperHero: Spiderman
            Strength: 8.7
            Skills: ['time travel', 'fly', 'joking', 'eat pizza']
            Tasks: ['Save the world', 'Learn Python']
    """
    hero1.assign_task(task1)
    hero1.assign_task(task2)
    print(hero1)

    print('\n==== TODO#4/4 ====')
    """
    TODO4/4
    Add more code to the two classes so that when running the test
          code below, the following output will be produced:
    SuperHero: Spiderman
            Strength: 8.7
            Skills: ['time travel', 'fly', 'joking', 'eat pizza']
            Tasks: ['Save the world', 'Learn Python']
    Task:   Save the world
            Difficulty: 7.3
            Done: True
    """
    hero1.complete_task(task1)
    print(hero1)
    print(task1)

if __name__ == '__main__':
    test()

# -------------------------------------

# Exercise 2: write a dataclass Book that has the following attributes:
#       title, author, isbn, publication year, genre
#   Test the class.
from dataclasses import dataclass
@dataclass
class Book:
    title: str
    author: str
    isbn: str
    publication_year: int
    genre: str

def main():
    book1 = Book('1713', 'Ethan Azevedo', 
                 '123456789', 1449, 'Monkey zoo')

    book2 = Book('Finding the Island', 'Jackie Huang',
                 '987654321', 1536, 'Entertainment and horror')

    print('\n')
    print(book1)
    print('\n')
    print(book2)
    print('\n')

main()