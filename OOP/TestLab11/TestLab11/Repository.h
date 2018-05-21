//
//  Repository.hpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Repository_h
#define Repository_h

#include <stdio.h>
#include "Painting.h"
#include <vector>


class Repository{
private:
    std::vector <Painting> data;
public:
    void addPaintintg(Painting p);
    void removePainting(Painting p);
    int findPaint(const std::string& artist,const std::string& title,int year);
    std::vector<Painting> getAll();
};

#endif /* Repository_hpp */
