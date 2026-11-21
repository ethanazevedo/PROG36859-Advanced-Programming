from dataclasses import dataclass

@dataclass
class Student:
  sid: int 
  name: str
  age: int 
  grade: float 

students = [
  Student(100, 'Alice', 21, 3.8),
  Student(101, 'Bob', 18, 3.2),
  Student(102, 'Cendy', 19, 2.7)
]

# 1. File IO
def file_io():
  file_name = 'students.txt'
  with open(file_name, 'w') as file:
     for s in students:
       file.write(f'{s.sid}\n{s.name}\n{s.age}\n{s.grade}\n') # only string
  
  students_file = []
  with open(file_name, 'r') as file:
    line = file.readline() # include \n
    while line != '':
      sid = int(line)
      name = file.readline().rstrip()
      age = int(file.readline())
      grade = float(file.readline())
      students_file.append(Student(sid, name, age, grade))
      line = file.readline()
  print(students_file)  

# 2. CSV file IO
# - Comma-Separated-Values, standard format for tabular data
# - Row: one record, Column: attribute
import csv 

def csv_io():
  csv_file = 'students.csv'
  with open(csv_file, 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['id', 'name', 'age', 'grade']) # header
    for s in students:
      writer.writerow([s.sid, s.name, s.age, s.grade])

  students_csv = []
  with open(csv_file, 'r', newline='') as file:
    reader = csv.reader(file)
    next(reader) # skip header
    for row in reader:
      sid, name, age, grade = row # all strings
      students_csv.append(Student(int(sid), name, int(age), float(grade)))
  print(students_csv)
   
# 3. JSON file IO
# - JavaScript Object Notation
# - Standard format for data interchange in web applications
# - Python types: bool  str   int/float   list/tuple  dict
# - JSON types:   bool  string  number    array       object
# - dump/dumps: convert to JSON format stored to file/string
# - load/loads: parse JSON data stored in file/string

import json 

def json_io():
  # other ways: vars() or __dict__
  students_dict = [ {'sid': s.sid, 'name': s.name, 
                    'age': s.age, 'grade': s.grade}  
                    for s in students]
  print(students_dict)
  json_str = json.dumps(students_dict)
  print(json_str)

  # server can send json_str back to client...
  students_json = []
  json_data = json.loads(json_str)
  print(json_data)
  for data in json_data:
    student = Student(data['sid'], data['name'], data['age'], data['grade'])
    students_json.append(student)
  print(students_json)

def main():
  file_io()
  csv_io()
  json_io()

main()
