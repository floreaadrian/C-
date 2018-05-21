//
//  Repository.cpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Repository.h"
#include <iostream>

void Repository::addPaintintg(Painting p){
    this->data.push_back(p);
}

int Repository::findPaint(const std::string& artist,const std::string& title,int year){
    for(int i=0;i<this->data.size();++i){
        if(this->data[i].getTitle()==title && this->data[i].getArtist()==artist && this->data[i].getYear()==year){
            return i;
        }
    }
    return -1;
}

void Repository::removePainting(Painting p){
    int pos=findPaint(p.getArtist(), p.getTitle(), p.getYear());
    if(pos!=-1){
        for(int i=pos;i<this->data.size()-1;++i)
            this->data[i]=this->data[i+1];
        this->data.pop_back();
    }
}

std::vector<Painting> Repository::getAll(){
    return this->data;
}
