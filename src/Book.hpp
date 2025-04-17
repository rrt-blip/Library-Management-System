//
//  Book.hpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#ifndef Book_hpp
#define Book_hpp

#include "LibItem.hpp"
#include <vector>
class Book: public LibItem{
private:
    int pageNo;
    string genre;
    vector<Book> books;
    
public:
    /* Contructor to initialize the object BOOK, calls inherited constructor LIbrary*/
    Book(const string&_title,
         const string&_author,
         const string&_publisher,
         const string&_isbn,
         bool _availible,
         int _pageNo,
         const string&_genre)
    :LibItem(_title, _author, _publisher, _isbn, _availible), pageNo(_pageNo), genre(_genre){}
    Book():LibItem(),pageNo(0), genre("") {}
    ~Book(){}
    string getGenre()const {return genre;}
    int getPageNo() const{return pageNo;}
    void setGenre(const string& genre){this->genre = genre;}
    void setPageNo(int pageNo){this->pageNo = pageNo;}
    void displayItem()const;
};


#endif /* Book_hpp */
