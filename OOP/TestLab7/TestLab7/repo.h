//
//  repo.hpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef repo_h
#define repo_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include "team.h"

class Repository{
private:
    std::vector<Teams> data;
public:
    int addTeam(std::string name,std::string country,int score);
    int findPos(std::string name);
    Teams findTeam(std::string name);
    std::vector<Teams> getVector(){return data;}
    int Pair(std::string team1,std::string team2,std::string winning);
    void increaseScore(std::string team);
    void deleteTeam(std::string name);
    void tests();
    void addTest();
};

#endif /* repo_hpp */
