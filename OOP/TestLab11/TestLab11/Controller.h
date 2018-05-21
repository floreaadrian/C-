//
//  Controller.hpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Controller_h
#define Controller_h

#include <stdio.h>
#include <vector>
#include "Repository.h"
#include "Undo.h"

class Controller{
private:
    Repository repoAll;
    Repository repoSpecialStorage;
    std::vector<UndoOperation*> undo;
public:
    Controller(const Repository& r,const Repository& rS) : repoAll{r}, repoSpecialStorage{rS} {}
    void addPainting(const std::string& artist,const std::string& title,int year);
    void removePainting(const std::string& artist,const std::string& title,int year);
    void move(const std::string& artist,const std::string& title,int year);
    std::vector<Painting> getAll();
    std::vector<Painting> getAllSpecialStorage();
    void undoIt();
};

#endif /* Controller_hpp */
