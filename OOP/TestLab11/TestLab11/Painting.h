//
//  Painting.hpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Painting_h
#define Painting_h

#include <stdio.h>
#include <string>

class Painting{
private:
    std::string title;
    std::string artist;
    int year;
public:
    Painting(const std::string& art,const std::string& t,int y);
    std::string getTitle()const{return this->title;}
    std::string getArtist()const{return this->artist;}
    int getYear(){return this->year;}
};

#endif /* Painting_hpp */
