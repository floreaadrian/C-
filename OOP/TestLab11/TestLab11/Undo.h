//
//  Undo.hpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef Undo_h
#define Undo_h

#include <stdio.h>
#include "Repository.h"
#include "Painting.h"

class UndoOperation{
public:
    UndoOperation(){}
    virtual ~UndoOperation(){}
    virtual void executeUndo() = 0;
};

class UndoAddOperation : public UndoOperation{
private:
    Repository& paintingRepo;
    Painting p;
public:
    UndoAddOperation( Repository& re,Painting p1) : paintingRepo(re), p{p1} {}
    void executeUndo() override;
};

class UndoMoveOperation : public UndoOperation{
private:
    Repository& paintingRepo;
    Repository &specialRepo;
    
    Painting p;
public:
    UndoMoveOperation( Repository& re, Repository& r1,Painting p1) : paintingRepo(re),specialRepo(r1), p{p1} {}
    void executeUndo() override;
};

#endif /* Undo_hpp */
