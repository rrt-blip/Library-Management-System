//
//  main.cpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#include <iostream>
#include <fstream>
#include "Menu.hpp"
using namespace std;

int main() {
    
    Menu menu;
    menu.load();
    menu.UserMenu();

    return 0; 

    

}
