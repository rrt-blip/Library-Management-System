//
//  Student.cpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#include "Student.hpp"


Student::~Student(){
    delete[] borrowedBooks;
    delete [] borrowedCDs;
}

// Copy constructor
Student::Student(const Student& other)
    : name(other.name), surname(other.surname), studentID(other.studentID), numBorrowedBooks(other.numBorrowedBooks), numBorrowedCDs(other.numBorrowedCDs) {
    borrowedBooks = new std::string[numBorrowedBooks];
    for (int i = 0; i < numBorrowedBooks; ++i) {
        borrowedBooks[i] = other.borrowedBooks[i];
    }
    borrowedCDs = new std::string[numBorrowedCDs];
    for (int i = 0; i < numBorrowedCDs; ++i) {
        borrowedCDs[i] = other.borrowedCDs[i];
    }
}

// Assignment operator
Student& Student::operator=(const Student& other) {
    if (this == &other) {
        return *this;
    }

    // Free existing resources
    delete[] borrowedBooks;
    delete[] borrowedCDs;

    // Copy new resources
    name = other.name;
    surname = other.surname;
    studentID = other.studentID;
    numBorrowedBooks = other.numBorrowedBooks;
    numBorrowedCDs = other.numBorrowedCDs;

    borrowedBooks = new std::string[numBorrowedBooks];
    for (int i = 0; i < numBorrowedBooks; ++i) {
        borrowedBooks[i] = other.borrowedBooks[i];
    }

    borrowedCDs = new std::string[numBorrowedCDs];
    for (int i = 0; i < numBorrowedCDs; ++i) {
        borrowedCDs[i] = other.borrowedCDs[i];
    }

    return *this;
}


void Student::borrowBook(Library &library, const string &isbn) {
    // Add the book to the student's list of borrowed books
    if(library.IsBookAvailible(isbn)){
        string *tempBorrBooks = new string[numBorrowedBooks+1]; //increase the array by one
        for(int i=0; i<numBorrowedBooks; i++){
            tempBorrBooks[i] = borrowedBooks[i]; //copy everything from borrowed book array
        }
        tempBorrBooks[numBorrowedBooks] = isbn; //push the new book in the array
        delete[] borrowedBooks; //delete the other array. NO memory leaks :)
        borrowedBooks = tempBorrBooks; //set the pointer to the new array
        numBorrowedBooks++; //increase the number of books we borrowed
        library.borrowBook(isbn); //change the status of the book in the library
        
    }
    else{
        throw runtime_error("Book is not availible to borrow!");
    }
}


void Student::borrowCD(Library &library, const string &isbn){
    if(library.IsCDAvailible(isbn)){//if Cd is availible we can borrow it
        string *tempCDs = new string[numBorrowedCDs+1];
        
        for(int i =0; i< numBorrowedCDs; i++){
            tempCDs[i] = borrowedCDs[i];
        }
        
        tempCDs[numBorrowedCDs] = isbn;
        delete []borrowedCDs;
        
        borrowedCDs = tempCDs;
        numBorrowedCDs++;
        library.borrowCD(isbn);
    }
}

void Student::returnBook(Library &library, const string &isbn) { 
    int index = -1;
    for(int i =0; i< numBorrowedBooks; ++i){
        if(borrowedBooks[i]==isbn){//find the index of the book
            index = i;
            break;
        }
    }
    if(index !=-1){
        string *temp = new string[numBorrowedBooks-1];//create a temp array to store the books without the one we want to borrow
        for(int i=0, j=0; i<numBorrowedBooks; ++i){
            if(i!= index){
                temp[j++] = borrowedBooks[i];
            }
        }
        delete [] borrowedBooks;//delete old array
        borrowedBooks = temp;
        numBorrowedBooks--;
        library.returnBook(isbn);
    }
}

void Student::returnCD(Library &library, const string &isbn) { 
    int index=-1;
    for(int i=0; i<numBorrowedCDs; i++){
        if(borrowedCDs[i]==isbn){
            index = i;
            break;
        }
    }
    if(index != -1){
        string *temp = new string[numBorrowedCDs-1];
        for(int i=0, j=0; i<numBorrowedCDs; ++i){
            if(i!=index){
                temp[j++] = borrowedCDs[i];
            }
        }
        delete []borrowedCDs;
        borrowedCDs = temp;
        numBorrowedCDs--;
        library.returnCD(isbn);
    }
    
}

void Student::setBorrowedBooks(const std::string* books, int count) {
    delete[] borrowedBooks;
    borrowedBooks = new std::string[count];
    numBorrowedBooks = count;
    for (int i = 0; i < count; ++i) {
        borrowedBooks[i] = books[i];
    }
}

void Student::setBorrowedCDs(const std::string* cds, int count) {
    delete[] borrowedCDs;
    borrowedCDs = new std::string[count];
    numBorrowedCDs = count;
    for (int i = 0; i < count; ++i) {
        borrowedCDs[i] = cds[i];
    }
}


