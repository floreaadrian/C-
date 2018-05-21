//
//  repo.cpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "repo.h"


int Repository::addTeam(std::string name,std::string country,int score){
    //we verify if we have this team already by going to all the teams in function findPos
    if(findPos(name)==-1){
        //we add the team with push_back
        this->data.push_back(Teams(name,country,score));
        //we return 1 if it was succsesfull
        return 1;
    }
    return 0;
}

void Repository::deleteTeam(std::string name){
    int pos=findPos(name);
    for(int i=pos;i<this->data.size();++i)
        this->data[i]=this->data[i+1];
    this->data.pop_back();
}

int Repository::findPos(std::string name){
    //return the position of team if found
    for(int i=0;i<this->data.size();++i)
        if(this->data[i].getName()==name)
            return i;
    return -1;
}

Teams Repository::findTeam(std::string name){
    for(int i=0;i<this->data.size();++i)
        if(this->data[i].getName()==name)
            return this->data[i];
    return Teams{};
}

void Repository::increaseScore(std::string team){
    Teams team1=findTeam(team);
    int score=team1.getScore();
    std::string country =team1.getCountry();
    deleteTeam(team);
    score++;
    addTeam(team,country,score);
}

int Repository::Pair(std::string team1,std::string team2,std::string winning){
    if(winning!=team1 && winning!=team2)return 0;
    if(findPos(team1) ==-1 || findPos(team2) == -1)
        return 0;
    Teams team1team=findTeam(team1);
    Teams team2team=findTeam(team2);
    if(team1team.getScore()==team2team.getScore()){
        increaseScore(winning);
        return 1;
    }
    return 0;
}

void Repository::tests(){
    this->addTest();
}

void Repository::addTest(){
    assert(addTeam("a","b",1)==1);
    assert(addTeam("a","b",1)==0);
    assert(this->data.size()==1);
    assert(addTeam("v","b",1)==1);
    assert(addTeam("d","b",1)==1);
    assert(this->data[1].getName()=="v");
}
