# Python Stream IO - Exercises


# Exercise: 
#   - download a JSON file from: https://jsonplaceholder.typicode.com/todos, save it
#       to your computer as a text file. 
#   - define a class Todo to represent the JSON data. Use @dataclass
#   - write a function to load the file to a Python list of dictionary, 
#       then create a Python list of Todo objects from it.
#   - Create a dictionary to calculate the numbers of the user, the completed and not completed todos.
#       Print the dictionary. The dictionary is in format as:
#       {'users': <number_of_users>, 
#        'completed': <number_of_completed>>, 
#        'not completed': <number_of_not_completed>}
import json
from dataclasses import dataclass


# Exercise: 
#   - create some data of type bool, int, float, string, list, and dictionary
#   - create some objects from a class Game(name, year, rate)
#   - serialize(dumps/dump) all data to strings and files 
#   - deserialize(loads/load) all data back from the strings and file

