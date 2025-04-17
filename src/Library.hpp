//
//  Library.hpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#ifndef Library_hpp
#define Library_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Book.hpp"
#include "CD.hpp"

using namespace std;
/// Container Class that Holds BOOKs, CDs, and Students.
class Library{
public:
    vector<CD> cds;
    vector<Book> books;
  
    ///  Loads books from a file.
    /// - Parameter filename: The name of the file to load from.
    void LoadBook(const string& filename);
    
    /// Saves books to a file.
    /// - Parameter filename: The name of the file to save to.
    void SaveBook(const string& filename);
   
    /// Loads CDs from a file.
    /// - Parameter filename:  The name of the file to load from.
    void LoadCd(const string& filename);
    /// Saves CDs in a file.
    /// - Parameter filename:  The name of the file to save from.
    void SaveCd(const string& filename);
    /// Adds a book to the library's collection
    /// - Parameter book: The book to add
     void addBook(const Book& book) {
         books.push_back(book);
     }
    
    /// Adds a cd to the library's collection.
    /// - Parameter cd: cd The CD to add.
    void addCD(const CD& cd){
        cds.push_back(cd);
    }
    
    
    /// Searches the book based on ISBN and returns a pointer of that book object
    /// - Parameter isbn: isbn for the search book
    Book* findBookByISBN(const string& isbn);
    
    /// Searches for CD based on given ISBN and return a poiner to the CD object
    /// - Parameter isbn: isbn for the search CD
    CD *findCDByISBN(const string& isbn);
    
    /// Checks if book is in the file
    /// - Parameter searchisbn: const string isbn of the book we want to search
    bool isBookInFile(const string &searchisbn);
    
    /// Checks if CD is in the file
    /// - Parameter searchisbn: const string isbn of the CD we search
    bool isCDInFile(const string &searchisbn);
    
    /// Changes book availibility
    /// - Parameters:
    ///   - isbn: isbn of the book we want to change
    ///   - status: status we want to set
    void changeBookStatus(const string &isbn, bool status);
    
    /// changes CD  status
    /// - Parameters:
    ///   - isbn: isbn of CD we want to change
    ///   - status: status we want to set
    void changeCDStatus(const string &isbn, bool status);
    
    /// Prints the Data of All Books
    void printBooks();
    
    /// Prints the Data of All CDs
    void printCDs();
    
    ///Function to check if the book is availible or not
    bool IsBookAvailible(const string &isbn) {
        Book *b = findBookByISBN(isbn);
        if(b==nullptr){
            return false;
        }
        else return true;
    }
    
    bool IsCDAvailible(const string &isbn){
        CD *cd = findCDByISBN(isbn);
        if(cd==nullptr){
            return false;
        }
        return true;
    }
    /***Functions to change status of availibility after we borrow or return them ***/
    
    void borrowBook(const string &isbn){
        changeBookStatus(isbn, false);
    }
    
    void borrowCD(const string &isbn){
        changeCDStatus(isbn, false);
    }
  
    void returnBook(const string &isbn){
        changeBookStatus(isbn, true);
    }
    
    void returnCD(const string &CDisbn){
        changeCDStatus(CDisbn, true);
    }
};
#endif /* Library_hpp */
