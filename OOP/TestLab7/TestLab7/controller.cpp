//
//  controller.cpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "controller.h"
#include <algorithm>

Controller::Controller(const Repository &repo){
    this->repo=repo;
}

int Controller::addCtrl(std::string name,std::string country){
    //return 1 if team was added and 0 if not,score will be put 0 by default
    return this->repo.addTeam(name, country,0);
}

int Controller::pairTeams(std::string team1,std::string team2,std::string winning){
    return this->repo.Pair(team1,team2,winning);
}

bool funcSort(Teams a,Teams b){
    //this is the function that compares the scores
    return a.getScore()>b.getScore();
}

std::vector<Teams> Controller::getSorted(){
    //we get a copy of a vector
    std::vector <Teams> sortedTeams= this->repo.getVector();
    //we sort it using function from algorithm
    sort(sortedTeams.begin(),sortedTeams.end(),funcSort);
    return sortedTeams;
}

void Controller::tests(){
    this->testAdd();
    this->testSort();
}

void Controller::testAdd(){
    assert(this->repo.addTeam("as", "bb",0)==1);
    assert(this->repo.addTeam("as", "bb",0)==0);
    assert(this->repo.addTeam("fdsa", "fdas",0)==1);
}


void Controller::testSort(){
    assert(this->repo.addTeam("fsda", "bb",2)==1);
    assert(this->repo.addTeam("as", "bb",1)==0);
    assert(this->repo.addTeam("fdsa", "fdas",0)==0);
    std::vector <Teams> tut = getSorted();
    //assert(tut[1].getName()=="as");
}

