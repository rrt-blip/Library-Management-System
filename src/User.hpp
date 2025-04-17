//
//  User.hpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#ifndef User_hpp
#define User_hpp

#include <string>
#include <iostream>
using namespace std;

enum AccessLevel { STUDENT, ADMIN };
class User{
private:
    string username;
    AccessLevel accessLevel;
public:
    User(AccessLevel acc1,string _username):
    accessLevel(acc1), username(_username){}
    User(): accessLevel(STUDENT),username("") {}
    void setUserame(const string &username){this->username = username;}
    void setAccessLevel(AccessLevel acc){this->accessLevel = acc;}
    string getUsername()const{return username;}
    AccessLevel getAccesLevel()const{return accessLevel;}
};


#endif /* User_hpp */
