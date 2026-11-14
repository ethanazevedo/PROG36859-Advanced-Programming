
# Python Dictionaries - Exercises


# Exercise: 
#   - write a class Student(sid, name, marks)
#   - write a function that reads 3 pieces of data from the user and return a list of student objects
#   - write a function that takes a list of students, return the average, min, and max marks 
#   - write a function that given a list of students, return two dictionaries, (grade:list_of_students) and (name:grade)
#       - grade: 'A', 'B', 'C', 'D', 'F' corresponds to marks 90-100, 80-89, 70-79, 60-69, 0-59    


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
    # TODO
    pass

def print_averages(my_gradebook):
    # TODO
    pass

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
