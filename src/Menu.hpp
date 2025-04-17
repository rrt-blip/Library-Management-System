//
//  Menu.hpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 15.5.24.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include "Admin.hpp"
#include "Student.hpp"
#include "Library.hpp"
#include <stdlib.h>

class Menu{
public:
    Library library;
    Admin admin;
    Student student;
    
    string bookFileName;
    string cdFileName;
    string stFileName;
    
    Menu() : bookFileName("books.txt"), cdFileName("cds.txt"), stFileName("students.txt") {}
    
    void load();//function to load all the files
    
    void AdminBookMenu();//Book menu for admin
    void AdminCDMenu();//cd menu for admin
    void AdminStudentMenu();//student menu for admin
    void AdminMenu();//admin menu .i.e book, cd, student
    void StudentMenu();//student menu, i.e borrow return
    void UserMenu();//User menu. i.e student?admin
    
    
    
};
#endif /* Menu_hpp */
