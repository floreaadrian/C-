//
//  Controller.cpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Controller.h"
#include <iostream>

void Controller::addPainting(const std::string& artist,const std::string& title,int year){
    this->repoAll.addPaintintg(Painting(artist,title,year));
    UndoOperation* a = nullptr;
    a = new UndoAddOperation(this->repoAll,Painting(artist,title,year));
    this->undo.push_back(a);
}

void Controller::removePainting(const std::string& artist,const std::string& title,int year){
    this->repoAll.removePainting(Painting(artist,title,year));
}

void Controller::undoIt(){
   // std::cout<<this->undo.size();
    if(this->undo.size()>0){
    this->undo[this->undo.size()-1]->executeUndo();
        this->undo.pop_back();}
}

void Controller::move(const std::string& artist,const std::string& title,int year){
    if(this->repoAll.findPaint(artist,title,year)!=-1){
        removePainting(artist,title,year);
        this->repoSpecialStorage.addPaintintg(Painting(artist,title,year));
        UndoOperation* a = nullptr;
        a = new UndoMoveOperation(this->repoAll,this->repoSpecialStorage,Painting(artist,title,year));
        this->undo.push_back(a);
    }
}

std::vector<Painting> Controller::getAll(){
    return this->repoAll.getAll();
}

std::vector<Painting> Controller::getAllSpecialStorage(){
    return this->repoSpecialStorage.getAll();
}
