//
//  Library.cpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//
#include "Library.hpp"
/**Function that loads the books from the file and saves it in the vector books**/
void Library::LoadBook(const string& filename){
    ifstream inFile(filename);//opening the file
    if (!inFile.is_open()) {
        throw runtime_error("Failed to open the file: " + filename);
    }

    string line = "";
    while (getline(inFile, line)) {//itearte through the file and get each line
        string title, author, publisher, isbn, genre;
        bool available;
        int pageNo;
        string tempString;//buffer string to save the data that is not string . i.e. the availible and page num,ber
        
        stringstream inputString(line);//use the string stream to read the line
        getline(inputString, title, ',');//read until the ','
        getline(inputString, author, ',');
        getline(inputString, publisher, ',');
        getline(inputString, isbn, ',');
        getline(inputString, tempString,',');//save the availible in the buffer
        available = (tempString == "true"); //change the string to bool
        getline(inputString, tempString,',');
        pageNo = atoi(tempString.c_str());//change the string to integer
        getline(inputString, genre);
        
        Book book(title, author, publisher, isbn, available, pageNo, genre); //create Book object and initialize it with the data from file
        books.push_back(book);//push it into our book vector
        line ="";//empty the line for the next iteration
   }
    inFile.close();//close the file
}


void Library::SaveBook(const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& book : books) {
            // Write book information to the file, separating attributes with commas
            outFile << book.getTitle() << ","
                    << book.getAuthor() << ","
                    << book.getPublisher() << ","
                    << book.getIsbn() << ","
                    << book.getStatus() << ","
                    << book.getPageNo() << ","
            << book.getGenre() << endl;
        }
    } else {
        throw runtime_error("Failed to open file: "+filename);
    }
    cout << "Book information saved to file: " << filename << endl;
    outFile.close();
}




/**function to load the Cd data from file**/
void Library::LoadCd(const string &filename){
    ifstream inFile(filename);//opening the file
    if (!inFile.is_open()) {
        throw runtime_error("Failed to open the file: " + filename);
    }

    string line = "";
    while (getline(inFile, line)) {//itearte through the file and get each line
        string title, author, publisher, isbn;
        bool available = true;
        int tracks;
        double duration;
        string tempString;//buffer string to save the data that is not string . i.e. the availible and page num,ber
        
        stringstream inputString(line);//use the string stream to read the line
        getline(inputString, title, ',');//read until the ','
        getline(inputString, author, ',');
        getline(inputString, publisher, ',');
        getline(inputString, isbn, ',');
        getline(inputString, tempString,',');//save the availible in the buffer
        tracks = atoi(tempString.c_str()); //change the string to bool
        getline(inputString, tempString,',');
        duration = atof(tempString.c_str());//change the string to integer
        
        CD cd(title, author, publisher, isbn, available, tracks, duration);
        cds.push_back(cd);//push it into our cd vector
        line ="";//empty the line for the next iteration
   }
    inFile.close();//close the file
}

/**function that saves CD data in the file**/
void Library::SaveCd(const string &filename){
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& cd: cds) {
            // Write book information to the file, separating attributes with commas
            outFile << cd.getTitle() << ","
                    << cd.getAuthor() << ","
                    << cd.getPublisher() << ","
                    << cd.getIsbn() << ","
                    << cd.getStatus() << ","
                    << cd.getTracks() << ","
            << cd.getDuration() << endl;
        }
    } else {
        throw runtime_error("Failed to open file: " + filename);
    }
    cout << "CD information saved to file: " << filename << endl;
    outFile.close();
}

Book* Library::findBookByISBN(const string& isbn) {
    for (auto& item : books) {
        // Check if the item is a Book and if its ISBN matches the given ISBN
        if (dynamic_cast<Book*>(&item) != nullptr && item.getIsbn() == isbn) {
            return dynamic_cast<Book*>(&item); // Return a pointer to the found Book
        }
    }
    return nullptr; // Return nullptr if the Book is not found
}

CD* Library::findCDByISBN(const string& isbn){
    for(auto& item : cds){
        if(dynamic_cast<CD*>(&item) != nullptr && item.getIsbn() == isbn){
            return dynamic_cast<CD*>(&item);
        }
    }
    return nullptr;
}

bool Library::isBookInFile(const string &searchisbn)
{
    Book *book = findBookByISBN(searchisbn);
    if(book){
        return true;
    }else{
       
        return false;
    }
}

bool Library::isCDInFile(const string &searchisbn){
    CD *cd = findCDByISBN(searchisbn);
    if(cd){
        return true;
    }else{
        return false;
    }
}

void Library::changeBookStatus(const string &isbn, bool status){
    Book *book = findBookByISBN(isbn);
    
    if(book){
        book->setStatus(status);
    }
}

void Library::changeCDStatus(const string &isbn, bool status){
    CD *cd = findCDByISBN(isbn);
    
    if (cd) {
        cd->setStatus(status);
    }
}



void Library::printBooks(){
    if(books.empty()){
        cout<<"Library Contains No Books"<<endl;
        return;
    }
    
    for(const auto &book: books){
        cout << "Title: " << book.getTitle() << endl;
        cout << "Author: " << book.getAuthor() << endl;
        cout << "Publisher: " << book.getPublisher() << endl;
        cout << "Genre: "<<book.getGenre()<<endl;
        cout << "ISBN: " << book.getIsbn() << endl;
        cout << "Status: " << book.getStatus() <<endl;
        cout <<"Page Number: " << book.getPageNo()<<endl;
        cout << "------------------------" << endl;
    }
}


void Library::printCDs(){
    if (cds.empty()) {//if the vector is empy, return
        cout<<"Library Contains No CDs"<<endl;
        return;
    }
    for(const auto &cd: cds){//iterate through the vector and print everything
        cout << "Title: " << cd.getTitle() << endl;
        cout << "Author: " << cd.getAuthor() << endl;
        cout << "Publisher: " << cd.getPublisher() << endl;
        cout << "Tracks no.: "<<cd.getTracks()<<endl;
        cout << "ISBN: " << cd.getIsbn() << endl;
        cout << "Status: " << cd.getStatus() <<endl;
        cout << "Duration: " << cd.getDuration()<<endl;
        cout << "------------------------" << endl;
    }
}



