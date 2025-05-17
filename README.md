# Library-Management-System
A simple **Command Line Interface (CLI)** based Library Management System developed in **C++** as part of the *Basics of Programming* course at BME. This system demonstrates the use of **Object-Oriented Programming (OOP)**, **File Handling**, and **Exception Handling** principles.

##  Project Description

The system manages the core functionalities of a library:
- Registering and modifying **Books**, **CDs**, and **Students**
- Searching and updating items using their **ISBN** or **ID**
- Maintaining data persistence through structured file handling
- Using class inheritance and polymorphism for maintainability

## I/O Files

The system reads and writes data to text files in CSV-like format:

- `books.txt`: Contains records of books (`Title, Author, Publisher, ISBN, Status, Page number, Genre`)
- `cds.txt`: Contains records of CDs (`Title, Artist, Publisher, ISBN, Status, Track number, Duration`)
- `students.txt`: Contains records of students and borrowed items (`Name, Surname, ID, Username | BorrowedBooks | BorrowedCDs`)

##  Features

-  Add, delete, and modify books and CDs
-  Search for books and CDs by ISBN
-  Register and manage students
-  Borrow and return books or CDs
-  File-based data persistence
-  Separate access levels: Admin and Student
-  Manual exception handling using `try-catch`

