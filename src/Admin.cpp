//
//  Admin.cpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#include "Admin.hpp"
/***Function that register CD by promting the user to enter data***/
void Admin::RegisterBook(Library &library,const string& filename){
    cout << "Enter the number of books you want to register:";
    int nbooks=0;
    cin >> nbooks;
    cin.ignore();
    
    ofstream ofile(filename, ios::app);//open file in append mode to add new cds
    if(!ofile.is_open()){
        throw runtime_error("Could not open File: " +filename+ " in Append Mode");//throw an error if file cannot open
    }
    
    string title, author, publisher, isbn, genre;
    int pageNo=0;
    for(int i=0; i<nbooks; i++){//itearting through the array of cds
        /**promting the user to enter the data of the cd**/
        cout << "===============================\n";
        cout << "     Register BOOKs\n"<<i+1 << "/" <<nbooks << endl;
        cout << "===============================\n";
        cout << "Enter the Title of the Book: ";
        getline(cin, title);
        cout << "Enter the Artist of the Book: ";
        getline(cin, author);
        cout << "Enter the Publisher: ";
        getline(cin, publisher);
        cout << "Enter the ISBN number of the Book: ";
        getline(cin, isbn);
        cout << "Enter the genre of the Book: ";
        getline(cin, genre);
        cout << "Enter the page number of the Book: ";
        cin >> pageNo;
        cin.ignore();
        
        /* creating object CD*/
        Book book(title, author, publisher, isbn, true, pageNo, genre);
        /* save object in the file*/
        ofile<<title<<","<<author<<","<<publisher<<","<<isbn<<","<<true<<","<<pageNo<<","<<genre<<endl;
        /* save it to the library vector*/
        library.addBook(book);
    }
    /* Close the file */
    ofile.close();
    cout<<"Book information succesfully saved to file: "<< filename <<endl;
}

/**function to register CD**/
void Admin::RegisterCd(Library &library, const string& filename){
    cout << "Enter the number of cds you want to register:";
    int ncds=0;
    cin >> ncds;
    cin.ignore();
    if(ncds<=0){
        throw runtime_error("Invalid number! Please enter a positive integer");
    }
    
    ofstream ofile(filename, ios::app);//open file in append mode to add new cds
    if(!ofile.is_open()){
        throw runtime_error("Could not open File: " +filename+ " in Append Mode");//throw an error if file cannot open
    }
    
    string title, author, publisher, isbn;
    int tracks=0;
    double duration = 0.0;
    for(int i=0; i<ncds; i++){//itearting through the array of cds
        /**promting the user to enter the data of the cd**/
        cout << "===============================\n";
        cout << "     Register CDs\n"<<i+1 << "/" << ncds<<endl;
        cout << "===============================\n";
        cout << "Enter the Title of the CD: ";
        getline(cin, title);
        cout << "Enter the Artist of the CD: ";
        getline(cin, author);
        cout << "Enter the Publisher: ";
        getline(cin, publisher);
        cout << "Enter the ISBN number of the CD: ";
        getline(cin, isbn);
        cout << "Enter the track no. of the CD: ";
        cin >> tracks;
        cout << "Enter the duration of the CD: ";
        cin >> duration;
        cin.ignore();
        
        /* creating object CD*/
        CD cd(title, author, publisher, isbn, true, tracks, duration);
        /* save object in the file*/
        ofile<<title<<","<<author<<","<<publisher<<","<<isbn<<","<<true<<","<<tracks<<","<<duration<<endl;
        library.addCD(cd);
    }
    /* Close the file */
    ofile.close();
    cout<<"CD information succesfully saved to file: "<< filename <<endl;
}


/// deletes book based on the given ISBN. Checks if Library is empty, throws an arror if yes.
/// calls function findBookByISBN(isbn) to search for the book with the isbn to delete, if it finds the book it proceeds to remove it from library
/// saves back the database to file
/// - Parameters:
///   - library:  reference to an object of the Library class.
///   - filename: string that holds the file name of the file we want to work on
void Admin::DeleteBook(Library &library, const string &filename) {
    string isbn;
    if(library.books.empty()){
        throw runtime_error("Library is empty. No books to delete");
    }
    cout << "Enter the ISBN of the book you want to delete: ";//store isbn of the book to delete
    cin >> isbn;
    
    
    Book* bookToDelete = library.findBookByISBN(isbn); //search book by that isbn
    if (bookToDelete != nullptr) {
        library.books.erase(remove_if(library.books.begin(), library.books.end(), [=](const Book& book) {
            return book.getIsbn() == isbn;
        }), library.books.end());//delete if you find the book that matches the isbn
        
        // save the new database back to file
        library.SaveBook(filename);
        
        cout << "Book with ISBN " << isbn << " deleted successfully." << endl;
    } else {
        cout << "Book with ISBN " << isbn << " not found." << endl;
    }
}



/*Modify the book data*/
void Admin::ModifyBook(Library &library, const string &filename){
    string searchIsbn;
    if (library.books.empty()) {//if there are no books throw an error
        throw runtime_error("Library contains no books to modify!");
    }
    
    cout<<"Enter the ISBN of the book you want to modify: ";
    cin>>searchIsbn;//get isbn of the book to modify
    cin.ignore();
    
    Book *bookToModify = library.findBookByISBN(searchIsbn);//find it and return a pointer to the book
    if(bookToModify != nullptr){//if we found it
        string title, author, publisher, genre;
        bool available;
        int pageNo;
        
        cout << "Enter the new title: ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, title);
        cout << "Enter the new author: ";
        getline(cin, author);
        cout << "Enter the new publisher: ";
        getline(cin, publisher);
        cout << "Enter the new genre: ";
        getline(cin, genre);
        cout << "Is the book available? (true/false): ";
        cin >> available;
        cout << "Enter the new page number: ";
        cin >> pageNo;
        cin.ignore();//change the data
        Book newData(title, author, publisher, searchIsbn, available, pageNo, genre);
        
        *bookToModify = newData;//make the book point to the new data
        library.SaveBook(filename);//save the modified book to the file
        cout << "Book data modified successfully." << endl;
    } else {
        // Book not found
        cout << "Book with ISBN " << searchIsbn << " not found." << endl;
    }
}

void Admin::DeleteCD(Library &library, const string &filename) {
    string isbn;
    if(library.cds.empty()){
        throw runtime_error("Library is empty. No books to delete");
    }
    cout << "Enter the ISBN of the book you want to delete: ";
    cin >> isbn;
    
    CD *cdToDelete = library.findCDByISBN(isbn);
    if(cdToDelete!=nullptr){
        library.cds.erase(remove_if(library.cds.begin(), library.cds.end(), [=](const CD& cd) {
            return cd.getIsbn() == isbn;
        }), library.cds.end());
        cout << "CD with ISBN " << isbn << " deleted successfully." << endl;
    }
    else{
        cout << "CD with ISBN " << isbn << " not found." << endl;
    }
}



void Admin::ModifyCD(Library &library, const string &filename) {
    string searchIsbn;
    if (library.cds.empty()) {
        throw runtime_error("Library contains no CDs to modify!");
    }
    
    cout<<"Enter the ISBN of the CD that you want to modify: ";
    cin>>searchIsbn;
    cin.ignore();
    
    CD* cdToModify = library.findCDByISBN(searchIsbn);
    if(cdToModify != nullptr){
        string title, author, publisher;
        bool available;
        int tracks;
        double duration;
        
        cout << "Enter the new title: ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, title);
        cout << "Enter the new author: ";
        getline(cin, author);
        cout << "Enter the new publisher: ";
        getline(cin, publisher);
        cout << "Is the book available? (true/false): ";
        cin >> available;
        cout << "Enter the new tracks number: ";
        cin >> tracks;
        cout<<"Enter the new duration time: ";
        cin>>duration;
        cin.ignore();
        CD newData(title, author, publisher, searchIsbn, available, tracks,duration);
        
        *cdToModify = newData;
        library.SaveCd(filename);
        cout << "CD data modified successfully." << endl;
    } else {
        // Book not found
        cout << "CD with ISBN " << searchIsbn << " not found." << endl;
    }
}




void Admin::RegisterStudent(const string &filename){
    cout << "Enter the number of students you want to register:";
    int nstd=0;
    cin >> nstd;
    if(nstd<=0){
        throw runtime_error("Invalid number! Please enter a positive integer");
    }
    
    ofstream ofile(filename, ios::app);//open file in append mode to add new students
    if(!ofile.is_open()){
        throw runtime_error("Could not open File: " +filename+ " in Append Mode");//throw an error if file cannot open
    }
    cin.ignore();
    string name, surname, id, username;
    for(int i = 0; i<nstd; i++){
        cout << "===============================\n";
        cout << "     Register CDs\n"<<i+1 << "/" << nstd<<endl;
        cout << "===============================\n";
        cout<<"Enter the name of the student: ";
        getline(cin, name);
        cout<<"Enter the surname of the student: ";
        getline(cin, surname);
        cout<<"Enter the ID of the student: ";
        getline(cin, id);
        cout<<"Enter the username of the student: ";
        getline(cin, username);
        
        int numBorrowBOOK, numBorrowCD;
        cout<<"How many borrowed books: ";
        cin>>numBorrowBOOK;
        cout<<"Give the ISBN of the borrowed books: ";
        string *borrowedBooks = new string[numBorrowBOOK];
        for(int i=0; i<numBorrowBOOK; i++){
            string isbn;
            getline(cin, isbn);
            borrowedBooks[i] = isbn;
        }
        cout<<"How many borrowed CDs: ";
        cin>>numBorrowCD;
        cout<<"Give the ISBN of the borrowed CDs: ";
        string *borrowedCDs = new string[numBorrowCD];
        for(int i=0; i<numBorrowCD; i++){
            string isbn;
            getline(cin, isbn);
            borrowedCDs[i] = isbn;
        }
        Student st(name, surname, id, username);
        st.setBorrowedBooks(borrowedBooks, numBorrowBOOK);
        st.setBorrowedCDs(borrowedCDs, numBorrowCD);
        
        // Write student information to file
        ofile << name << "," << surname << "," << id << "," << username << ",";
        for (int j = 0; j < numBorrowBOOK; j++) {
            ofile << borrowedBooks[j];
            if (j < numBorrowBOOK - 1) ofile << "|"; // Separate with different character
        }
        ofile << ",";
        for (int j = 0; j < numBorrowCD; j++) {
            ofile << borrowedCDs[j];
            if (j < numBorrowCD - 1) ofile << "|"; // Separate with different character
        }
        ofile << endl;

        addStudent(st);//add student data to our container
        
        delete[] borrowedBooks;//delete the dyn. allocated array
        delete[] borrowedCDs;
    }
    ofile.close();
}

/**Loads students from file to the vector collection students **/
void Admin::LoadStudents(const string& filename) {
    //open file in read mode
    ifstream ifile(filename);
    if (!ifile.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }

    string line;//parsing student info
    while (getline(ifile, line)) {
        stringstream ss(line);
        string name, surname, id, username;
        string booksStr, cdsStr;
        
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, surname, ',');
        getline(ss, username, ',');
        getline(ss, booksStr, ',');
        getline(ss, cdsStr, ',');

        // Create a new Student object
        Student st(name, surname, id, username);

        // Parse borrowed books
        if (!booksStr.empty()) {
            stringstream booksStream(booksStr);
            vector<string> borrowedBooks;
            string book;
            while (getline(booksStream, book, '|')) {
                borrowedBooks.push_back(book);
            }
            if (!borrowedBooks.empty()) {
                st.setBorrowedBooks(borrowedBooks.data(), borrowedBooks.size());
            }
        }

        // Parse borrowed CDs
        if (!cdsStr.empty()) {
            stringstream cdsStream(cdsStr);
            vector<string> borrowedCDs;
            string cd;
            while (getline(cdsStream, cd, '|')) {
                borrowedCDs.push_back(cd);
            }
            if (!borrowedCDs.empty()) {
                st.setBorrowedCDs(borrowedCDs.data(), borrowedCDs.size());
            }
        }

        // Add the student to the container
        addStudent(st);
    }

    ifile.close();
}

/*Function that saves the student data from students vector to file*/
void Admin::SaveStudent(const string &filename){
    ofstream ofile(filename);
    if (!ofile.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }
//save student data in file
    for (const auto& st : students) {
        ofile << st.getStudentID()<<"," << st.getName() << "," << st.getSurname() << "," << st.getUsername();

        // Save borrowed books
        string* borrowedBooks = st.getBorrowedBooks();
        int numBooks = st.getNumBorrowedBooks();
        if (numBooks > 0) {
            ofile << ",";
            for (int i = 0; i < numBooks; ++i) {
                if (i > 0) {
                    ofile << "|";
                }
                ofile << borrowedBooks[i];
            }
        } else {
            ofile << ",";
        }

        // Save borrowed CDs
        string* borrowedCDs = st.getBorrowedCDs();
        int numCDs = st.getNumBorrowedCDs();
        if (numCDs > 0) {
            ofile << ",";
            for (int i = 0; i < numCDs; ++i) {
                if (i > 0) {
                    ofile << "|";
                }
                ofile << borrowedCDs[i];
            }
        } else {
            ofile << ",";
        }

        ofile << endl;
    }

    ofile.close();
    cout << "Student information successfully saved to file: " << filename << endl;
}
/**Function to print the list of students **/
void Admin::printStudents() const {
    for (const auto& st : students) {
        cout << "Name: " << st.getName() << ", Surname: " << st.getSurname() << ", ID: " << st.getStudentID() << ", Username: " << st.getUsername();
        cout << ", Borrowed Books: ";
        for (int i = 0; i < st.getNumBorrowedBooks(); ++i) {
            if (i > 0) cout << ", ";
            cout << st.getBorrowedBooks()[i];
        }
        cout << ", Borrowed CDs: ";
        for (int i = 0; i < st.getNumBorrowedCDs(); ++i) {
            if (i > 0) cout << ", ";
            cout << st.getBorrowedCDs()[i];
        }
        cout << endl;
    }
}

/*check if the student is in file/ return true if yes*/
bool Admin::isStudentinFile(const string &studentId, const string &filename){
    ifstream inputfile(filename);
    if(!inputfile.is_open()){//open file
        throw runtime_error("Could not open file: "+filename);
    }
    string line;
    while(getline(inputfile, line)){//read the lines till the end of file
        stringstream inputstring(line);
        string id;
        getline(inputstring, id, ',');
        if(studentId == id){
            return true;
        }
    }
    return false;
    
}

Student Admin::loadStudentData(const string &stID, const string &filename){
    ifstream inputfile(filename);
    if(!inputfile.is_open()){//open file
        throw runtime_error("Could not open file: "+filename);
    }
    string line;
    while(getline(inputfile, line)){
        stringstream inputstring(line);
        string id, name, surname, username;
        getline(inputstring, id,',');//get id
        if(id==stID){//if the id matches, get all the data on that line
            getline(inputstring, name, ',');
            getline(inputstring, surname, ',');
            getline(inputstring, username, ',');
            Student newst(name, surname, id, username);//create a new student object
            return newst;//return this
        }
    }
    throw runtime_error("Student not found: "+ stID);
}

///CHAT GPT
void Admin::saveStudentData(const Student& st, const string &filename){
    ifstream inputfile(filename);
    if(!inputfile.is_open()){//open file
        throw runtime_error("Could not open file: "+filename);
    }
    ofstream ofile("temp.txt");
    string line;
    bool found = false;
    
    while(getline(inputfile, line)){
        stringstream ss(line);
        string id;
        getline(ss, id, ',');
        
        if(id == st.getStudentID()){
           ofile<<st.getStudentID()<<","
                <<st.getName()<<","
                <<st.getSurname()<<","
                <<st.getUsername()<<",";
            for(int i=0; i<st.getNumBorrowedBooks(); ++i){
                ofile<<st.getBorrowedBooks()[i];
                if(i<st.getNumBorrowedBooks() - 1) ofile<<"|";
            }
            ofile<<",";
            for (int i = 0; i < st.getNumBorrowedCDs(); ++i) {
               ofile << st.getBorrowedCDs()[i];
               if (i < st.getNumBorrowedCDs() - 1) ofile << ";";
           }
            ofile <<endl;
            found = true;
        }
    }
    if (!found) {
            ofile << st.getStudentID() << ","
                    << st.getName() << ","
                    << st.getSurname() << ","
                    << st.getUsername() << ",";
            for (int i = 0; i < st.getNumBorrowedBooks(); ++i) {
                ofile << st.getBorrowedBooks()[i];
                if (i < st.getNumBorrowedBooks() - 1) ofile << ";";
            }
            ofile << ",";
            for (int i = 0; i < st.getNumBorrowedCDs(); ++i) {
                ofile << st.getBorrowedCDs()[i];
                if (i < st.getNumBorrowedCDs() - 1) ofile << ";";
            }
            ofile << endl;
        }

        inputfile.close();
        ofile.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    
    
}
