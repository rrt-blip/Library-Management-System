//
//  Admin.hpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#ifndef Admin_hpp
#define Admin_hpp
#include "User.hpp"
#include "Library.hpp"
#include "Student.hpp"
#include <iostream>
class Admin: public User{
private:
    string ID;
public:
    Admin(string _username, AccessLevel acc, string _ID):User(acc, _username), ID(_ID){}
    Admin(): User(), ID(""){}
    vector<Student> students;

    void RegisterCd(Library &library, const string& filename);
    void RegisterBook(Library &library, const string &filename);
    void DeleteBook(Library &library, const string &filename);
    /// Modifies data of the book from given ISBN
    /// - Parameters:
    ///   - library: library collection which has the books
    ///   - filename: filename on which we load and save the data
    void ModifyBook(Library &library, const string &filename);
    void DeleteCD(Library &library, const string &filename);
    void ModifyCD(Library &library, const string &filename);
    void RegisterStudent(const string &filename);
    /// Loads student data from file, adds it to the student collection
    /// - Parameter filename: string filename
    void LoadStudents(const string& filename);
    /// Saves Student data in the file
    /// - Parameter filename: string file name
    void SaveStudent(const string &filename);
/// Adds students to the library's collection
/// - Parameter st: The student object to add
    void addStudent(const Student& st){students.push_back(st);}
    /// Prints the data of All students
    void printStudents()const;
    //checks if the student is in file by checking if the id match
    bool isStudentinFile(const string &studentId, const string &filename);
    
    Student loadStudentData(const string& stID, const string &filename);
    void saveStudentData(const Student &student, const string &filename);
    
};
#endif /* Admin_hpp */
