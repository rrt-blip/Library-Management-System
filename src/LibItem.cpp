//
//  LibItem.cpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#include "LibItem.hpp"


void LibItem::displayItem()const{
    cout<<"------------------------";
    cout<<"Author: "<< getAuthor() <<endl;
    cout<<"Title: "<< getTitle() <<endl;
    cout<<"ISBN: "<< getIsbn()<<endl;
    cout<< "Status: ";
    if(getStatus() == 0){
        cout<<"Availible!"<<endl;
    }else {
        cout <<"Not Availible!"<<endl;
    }
}
