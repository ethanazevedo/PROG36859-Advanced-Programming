
# Python Dictionaries - Exercises


# Exercise: 
#   - write a class Student(sid, name, marks)
#   - write a function that reads 3 pieces of data from the user and return a list of student objects
#   - write a function that takes a list of students, return the average, min, and max marks 
#   - write a function that given a list of students, return two dictionaries, (grade:list_of_students) and (name:grade)
#       - grade: 'A', 'B', 'C', 'D', 'F' corresponds to marks 90-100, 80-89, 70-79, 60-69, 0-59    


class Student:
    def __init__(self, sid, name, marks):
        self.sid = sid
        self.name = name
        self.marks = marks

    def __str__(self):
        return f'{self.sid} {self.name} {self.marks}'


def read_students():
    students = []

    for i in range(3):
        sid = int(input('Enter student ID: '))
        name = input('Enter student name: ')
        marks = float(input('Enter student marks: '))

        s = Student(sid, name, marks)
        students.append(s)

    return students


def calculate_marks(students):
    marks = [s.marks for s in students]

    average = sum(marks) / len(marks)
    minimum = min(marks)
    maximum = max(marks)

    return average, minimum, maximum


def create_dictionaries(students):
    grade_students = {}
    name_grade = {}

    for s in students:
        if s.marks >= 90:
            grade = 'A'
        elif s.marks >= 80:
            grade = 'B'
        elif s.marks >= 70:
            grade = 'C'
        elif s.marks >= 60:
            grade = 'D'
        else:
            grade = 'F'

        if grade not in grade_students:
            grade_students[grade] = []

        grade_students[grade].append(s)
        name_grade[s.name] = grade

    return grade_students, name_grade


def main():
    students = read_students()

    average, minimum, maximum = calculate_marks(students)

    print('\n==== Marks Summary ====')
    print('Average:', average)
    print('Minimum:', minimum)
    print('Maximum:', maximum)

    grade_students, name_grade = create_dictionaries(students)

    print('\n==== Grade: Students ====')
    for grade, students in grade_students.items():
        print(grade, ':')
        for s in students:
            print(' ', s)

    print('\n==== Name: Grade ====')
    for name, grade in name_grade.items():
        print(name, ':', grade)


main()



# Exercise: write a Python program to process your own marks obtained in all tests of all subjects. 
#   - Write the following two functions. 
#   - Function 1: create_gradebook: this function will read a few subject names, and for each subject, 
#       some test names (lab, quiz, asgn, exam) and the scores. It creates a dictionary to store these 
#       data and return the dictionary. Note: test name must be starting with one of the four types: 
#       "lab", "quiz", "asgn", or "exam". The test name and the score must be entered in one line with 
#       a space in between, for example "lab1 9.3". Assume all user’s inputs are valid, so no validation 
#       on inputs are required. Also assume when the user enters a "done", it means no more tests or no 
#       more subjects to input.
#   - Function 2: print_averages: this function will accept a gradebook of dictionary type as created in 
#       Function 1. It prints a summary including the averages of all subjects and the averages of the 
#       four test types across all subjects. Format all averages to 2 digits after decimal point. 
#       Note: there can be some test types that have no score, for example no exam has been done.
#   - Note: Use dictionary instead of list. Do not use any global variables
def create_gradebook():
    gradebook = {}

    subject = input('= Enter subject name: ')

    while subject != 'done':
        tests = {}

        test = input('- Enter test name and score: ')

        while test != 'done':
            name, score = test.split()
            tests[name] = float(score)

            test = input('- Enter test name and score: ')

        gradebook[subject] = tests

        subject = input('= Enter subject name: ')

    return gradebook

def print_averages(my_gradebook):
    print('\n==== Summary ====')

    types = ['lab', 'quiz', 'asgn', 'exam']

    totals = {'lab': 0, 'quiz': 0, 'asgn': 0, 'exam': 0}
    counts = {'lab': 0, 'quiz': 0, 'asgn': 0, 'exam': 0}

    for subject in my_gradebook:
        total = 0
        count = 0

        for test, score in my_gradebook[subject].items():
            total += score
            count += 1

            for t in types:
                if test.startswith(t):
                    totals[t] += score
                    counts[t] += 1

        average = total / count
        print(f'Subject  : {subject:15} Average: {average:.2f}')

    print()

    for t in types:
        if counts[t] > 0:
            average = totals[t] / counts[t]
        else:
            average = 0

        print(f'Test Type: {t:15} Average: {average:.2f}')

'''
    Expected output:
    = Enter subject name: math
    - Enter test name and score: lab1 3.3 
    - Enter test name and score: lab2 4.4 
    - Enter test name and score: quiz1 5.5
    - Enter test name and score: asgn1 6.6
    - Enter test name and score: done
    = Enter subject name: python
    - Enter test name and score: quiz1 7.7
    - Enter test name and score: quiz2 8.8
    - Enter test name and score: lab1 9.9 
    - Enter test name and score: asgn1 8.8
    - Enter test name and score: asgn2 7.7
    - Enter test name and score: done
    = Enter subject name: database
    - Enter test name and score: asgn1 6.6
    - Enter test name and score: asgn2 5.5
    - Enter test name and score: lab2 4.4 
    - Enter test name and score: lab3 3.3 
    - Enter test name and score: quiz2 2.2
    - Enter test name and score: done
    = Enter subject name: done

    ==== Summary ====
    Subject  : math            Average: 4.95
    Subject  : python          Average: 8.58
    Subject  : database        Average: 4.40

    Test Type: lab             Average: 5.06
    Test Type: quiz            Average: 6.05
    Test Type: asgn            Average: 7.04
    Test Type: exam            Average: 0.00
'''
def main():
    print_averages(create_gradebook())
main()
