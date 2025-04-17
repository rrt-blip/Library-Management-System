//
//  CD.hpp
//  LibManSys
//
//  Created by Rrita Hajrizi on 12.5.24.
//

#ifndef CD_hpp
#define CD_hpp
#include "LibItem.hpp"

class CD: public LibItem{
private:
    int tracks;
    double duration;
public:
    CD(const string&_title,
         const string&_author,
         const string&_publisher,
         const string&_isbn,
         bool _availible,
         int _tracks,
         double _duration)
    :LibItem(_title, _author, _publisher, _isbn, _availible), tracks(_tracks), duration(_duration){}
    CD():LibItem(),tracks(0), duration(0.0) {}
    ~CD(){}
    void setTracks(int tracks){this->tracks = tracks;}
    int getTracks()const{return tracks;}
    void setDuration(double duration){this->duration= duration;}
    double getDuration()const{return duration;}
    void displayItem() const;
};

#endif /* CD_hpp */
