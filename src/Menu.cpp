//
//  Menu.cpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 15.5.24.
//

#include "Menu.hpp"

void Menu::load(){
    admin.LoadStudents(stFileName);
    library.LoadCd(cdFileName);
    library.LoadBook(bookFileName);
}

void Menu::AdminBookMenu(){
    char choice;
    char willContinue;
    bool running = true;
    while (running)//while user doesnt escape
    {
        system("clear");
        cout << "===============================\n";
        cout << "      Options for Books\n";
        cout << "===============================\n";
        cout << "1. Register a Book\n";
        cout << "2. Delete a Book \n";
        cout << "3. Modify a Book \n";
        cout << "4. Print all Book Data\n";
        cout << "Press Esc key to exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case '1':
                try{
                    admin.RegisterBook(library, bookFileName);
                }catch(const exception& e){
                    cerr << e.what() << endl;
                }
                break;
            case '2':
                try{
                    admin.DeleteBook(library, bookFileName);
                }catch(const exception& e){
                    cerr << e.what() << endl;
                }
                break;
            case '3':
                try{
                    admin.ModifyBook(library, bookFileName);
                }catch(const exception& e){
                    cerr << e.what() << endl;
                }
                break;
            case '4':
                library.printBooks();
                break;
            case 27: //ASCII for esc
                running = false;
                break;
            default:
                cout << "Invalid option\n";
                break;
        }

        if(choice != 27){
            cout << "Do you want to continue? Enter(y/n) : ";
            cin >> willContinue;
            if(tolower(willContinue) == 'n'){
                running = false;
            }
        }
    }
}

void Menu::AdminCDMenu(){
    char choice;
    char willContinue;
    bool running = true;
    while (running)//while user doesnt escape
    {
        system("clear");
        cout << "===============================\n";
        cout << "      Options for CDs\n";
        cout << "===============================\n";
        cout << "1. Register a CD\n";
        cout << "2. Delete a CD \n";
        cout << "3. Modify a CD \n";
        cout << "4. Print all CD Data\n";
        cout << "Press Esc key to exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case '1':
                try{
                    admin.RegisterCd(library, cdFileName);
                }catch(const exception& e){
                    cerr << e.what() << endl;
                }
                break;
            case '2':
                try{
                    admin.DeleteCD(library, cdFileName);
                }catch(const exception& e){
                    cerr << e.what() << endl;
                }
                break;
            case '3':
                try{
                    admin.ModifyCD(library, cdFileName);
                }catch(const exception& e){
                    cerr << e.what() << endl;
                }
                break;
            case '4':
                library.printCDs();
                break;
            case 27: //ASCII for esc
                running = false;
                break;
            default:
                cout << "Invalid option\n";
                break;
        }

        if(choice != 27){
            cout << "Do you want to continue? Enter(y/n) : ";
            cin >> willContinue;
            if(tolower(willContinue) == 'n'){
                running = false;
            }
        }
    }
}

void Menu::AdminStudentMenu(){
    char choice;
    char willContinue;
    bool running = true;
    while (running)//while user doesnt escape
    {
        system("clear");
        cout << "===============================\n";
        cout << "      Options for Students\n";
        cout << "===============================\n";
        cout << "1. Register a Student\n";
        cout << "2. Print all Student Data\n";
        cout << "Press Esc key to exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case '1':
                try{
                    admin.RegisterStudent(stFileName);
                }catch(const exception& e){
                    cerr << e.what() << endl;
                }
                break;
            case '2':
                admin.printStudents();
                break;
            case 27: //ASCII for esc
                running = false;
                break;
            default:
                cout << "Invalid option. Please choose again.\n";
                break;
        }

        if(choice != 27){
            cout << "Do you want to continue? Enter(y/n) : ";
            cin >> willContinue;
            if(tolower(willContinue) == 'n'){
                running = false;
            }
        }
    }
}

void Menu::AdminMenu() {
    int choice;
    char willContinue;
    bool isRunning = true;
    while(isRunning){
        system("clear");
        cout << "===============================\n";
        cout << "    Welcome Admin" << endl;
        cout << "    Please choose what you want to access:\n";
        cout << "===============================\n";
        cout << "1. Access BOOK Database\n";
        cout << "2. Access CD Database\n";
        cout << "3. Access Student Database\n";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                AdminBookMenu();
                break;
            case 2:
                AdminCDMenu();
                break;
            case 3:
                AdminStudentMenu();
                break;
            default:
                cout << "Invalid option\n";
        }

        cout << "Do you want to continue? Enter(y/n) : ";
        cin >> willContinue;
        if(tolower(willContinue) == 'n'){
            isRunning = false;
        }
    }
}

void Menu::StudentMenu(){
    int choice;
    system("clear");
    cout << "===============================\n";
    cout << "    Welcome Student" << endl;
    cout << "    Please choose what you want to access:\n";
    cout << "===============================\n";
    cout << "1. Borrow Book\n";
    cout << "2. Return Book\n";
    cout << "3. Borrow CD\n";
    cout << "4. Return CD\n";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            string isbn;
            cout << "Enter the isbn of the book you want to borrow: ";
            getline(cin, isbn);
            try{
                student.borrowBook(library, isbn);
            } catch(exception &e){
                cerr << e.what() << endl;
            }
            break;
        }
        case 2: {
            string isbn;
            cout << "Enter the isbn of the book you want to return: ";
            getline(cin, isbn);
            student.returnBook(library, isbn);
            break;
        }
        case 3: {
            string isbn;
            cout << "Enter the isbn of the CD you want to borrow: ";
            getline(cin, isbn);
            try{
                student.borrowCD(library, isbn);
            } catch(exception &e){
                cerr << e.what() << endl;
            }
            break;
        }
        case 4: {
            string isbn;
            cout << "Enter the isbn of the CD you want to return: ";
            getline(cin, isbn);
            student.returnCD(library, isbn);
            break;
        }
        default:
            cout << "Invalid option\n";
            break;
    }
}

void Menu::UserMenu(){
    string choice;
    cout << "===============================\n";
    cout << "    Welcome User" << endl;
    cout << "    Please choose what you want to access:\n";
    cout << "    ADMIN / STUDENT\n";
    cout << "===============================\n";
    getline(cin, choice);
    for (auto &c : choice) c = tolower(c);//make input lowercase
    if(choice == "admin"){
        AdminMenu();
    }else if(choice == "student"){
        StudentMenu();
    } else {
        cout << "Invalid input. Please choose 'Admin' or 'Student'.\n";
    }
}
