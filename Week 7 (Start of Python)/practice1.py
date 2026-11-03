
# TODO: Book class
class Book:
    pass


# TODO: Library class
class Library:
    pass


# =============================================================================

def test():

    print('==== TODO#1/4 ====')
    """
    TODO1/4
    Write a Book class so that when running the test code below,
    the following output will be produced:

    Book: Python Crash Course
        Author: Eric Matthes
        Pages: 560
        Borrowed: False

    Book: Clean Code
        Author: Robert C. Martin
        Pages: 464
        Borrowed: False
    """

    book1 = Book(name='Python Crash Course', author='Eric Matthes', pages=560)
    book2 = Book(name='Clean Code', author='Robert C. Martin', pages=464)

    print(book1)
    print(book2)


    print('\n==== TODO#2/4 ====')
    """
    TODO2/4
    Write a Library class so that when running the test code below,
    the following output will be produced:

    Library: Sheridan Library
        Location: Mississauga
    """

    library1 = Library(name='Sheridan Library', location='Mississauga')

    print(library1)


    print('\n==== TODO#3/4 ====')
    """
    TODO3/4
    Add code to the Library class so that when running the test code
    below, the following output will be produced:

    Library: Sheridan Library
        Location: Mississauga
        Books: ['Python Crash Course', 'Clean Code']
    """

    library1.add_book(book1)
    library1.add_book(book2)

    print(library1)


    print('\n==== TODO#4/4 ====')
    """
    TODO4/4
    Add more code to the two classes so that when running the test
    code below, the following output will be produced:

    Library: Sheridan Library
        Location: Mississauga
        Books: ['Python Crash Course', 'Clean Code']

    Book: Python Crash Course
        Author: Eric Matthes
        Pages: 560
        Borrowed: True
    """

    library1.borrow_book(book1)

    print(library1)
    print(book1)


if __name__ == '__main__':
    test()
