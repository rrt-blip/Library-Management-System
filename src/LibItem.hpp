//
//  LibItem.hpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#ifndef LibItem_hpp
#define LibItem_hpp


#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class LibItem{
private:
    /* attributes to characterize an item from library*/
    string title;
    string author;
    string publisher;
    string isbn;
    bool availible;
public:
    /*Contructor to initialize the item with default values*/
    LibItem(const string&_title,
            const string&_author,
            const string&_publisher,
            const string& _isbn ,
            bool _availible)
    : title(_title), author(_author), publisher(_publisher), isbn(_isbn), availible(_availible){};
    
    LibItem() : title(""), author(""), publisher(""), isbn(""), availible(false) {};
    
    
    virtual ~LibItem(){}
    /**getters to access private members of class Library**/
    string getTitle()const{
        return title;
    }
    string getAuthor()const{
        return author;
    }
    string getPublisher()const{
        return publisher;
    }
    string getIsbn()const{
        return isbn;
    }
    bool getStatus()const{
        return availible;
    }
    /***setters to  set the values to the private members of the class **/
    void setTitle(const string &title){
        this->title = title;
    }
    void setAuthor(const string &author){
        this->author = author;
    }
    void setPublisher(const string &publisher){
        this->publisher = publisher;
    }
    void setISBN(const string &isbn){
        this->isbn = isbn;
    }
    void setStatus(bool status){
        this->availible = status;
    }
    
    virtual void displayItem() const;
    
    
};

#endif /* LibItem_hpp */
