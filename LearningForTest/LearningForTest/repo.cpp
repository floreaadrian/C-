//
//  repo.cpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "repo.h"
#include <algorithm>

int Repository::add(int age, std::string name, int id){
    if(findPos(id)==-1)
    {
        this->data.push_back(Domain(age,name,id));
        return 1;
    }
    return 0;
}

int Repository::deleteObj(int id){
    int res=findPos(id);
    if(res==-1)
        return 0;
    for(int i=res;i<this->data.size();++i)
        this->data[i]=this->data[i+1];
    this->data.pop_back();
    return 1;
}

int Repository::update(int id, int newAge, std::string newName)
{
    int res=findPos(id);
    if(res==-1)
        return 0;
    this->deleteObj(id);
    this->add(newAge, newName, id);
    return 1;
}

bool lesss(Domain a,Domain b){
    return a.getId()<b.getId();
}

std::vector <Domain> Repository::getVectorSorted(){
    sort(this->data.begin(),this->data.end(),lesss);
    return this->data;
}

Domain Repository::find(int id)
{
    for(auto r:this->data){
        if(r.getId()==id)
            return r;
    }
    return Domain{};
}

int Repository::findPos(int id)
{
    for(int i=0;i<this->data.size();++i)
    {
        if(this->data[i].getId()==id)
            return i;
    }
    return -1;
}
