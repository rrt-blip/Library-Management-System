//
//  Book.cpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#include "Book.hpp"

void Book::displayItem()const{
    cout<<"Page no.:" << getPageNo()<<endl;
    cout<<"Genre: " << getGenre()<<endl;
}

