//
//  Student.hpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include "User.hpp"
#include "Library.hpp"
#include <stdio.h>
//TODO: Implement file handling for student

//TODO: Implement the interface for student

//TODO: Make the vectors into arrays and use new and delete

//TODO: Inherit Library class too and save all the data that they save
class Student: public User, public Library{
private:
    string name;
    string surname;
    string studentID;
    string* borrowedBooks;
    int numBorrowedBooks;
    string* borrowedCDs;
    int numBorrowedCDs;

public:
    // Constructor
    Student(const string& name, const string& surname, const string& studentID, const string &username)
            : User(STUDENT, username),
              name(name),
              surname(surname),
              studentID(studentID),
              borrowedBooks(nullptr),
              numBorrowedBooks(0),
              borrowedCDs(nullptr),
              numBorrowedCDs(0) {
        }
    Student() : User(), Library(), name(""), surname(""), studentID(""),
                   borrowedBooks(nullptr), numBorrowedBooks(0), borrowedCDs(nullptr), numBorrowedCDs(0) {}
    

    // Destructor
    ~Student();
    
    Student(const Student &theOther);
    
    Student& operator=(const Student &theOther);
    
    const string getName() const {
        return name;
    }
    
    const string getSurname() const {
        return surname;
    }
    
    const string getStudentID() const {
        return studentID;
    }
    
    void setName(const string &name){
        this->name = name;
    }
    
    void setSurname(const string &surname){
        this->surname = surname;
    }
    
    void setID(const string &studentID){
        this->studentID = studentID;
    }
    
    int getNumBorrowedBooks()const{
        return this->numBorrowedBooks;
    }
    
    int getNumBorrowedCDs()const{
        return this->numBorrowedCDs;
    }
    
    void setnumBorrowedBooks(int numBorrowedBooks){
        this->numBorrowedBooks = numBorrowedBooks;
    }
    
    void setnumBorrowedCDs(int numBorrowedCDs){
        this->numBorrowedCDs = numBorrowedCDs;
    }
    
    
  string* getBorrowedBooks() const {
            return borrowedBooks;
        }

 
    string* getBorrowedCDs() const {
        return this->borrowedCDs;
    }


        // Setters
    void setBorrowedBooks(const std::string* books, int count);
    void setBorrowedCDs(const std::string* cds, int count);

    void borrowBook(Library &library, const string &bookISBN);
    void borrowCD(Library &library, const string &cdISBN);
    void returnBook(Library &library, const string &isbn);
    void returnCD(Library &library, const string &isbn);


    };
    

#endif /* Student_hpp */
