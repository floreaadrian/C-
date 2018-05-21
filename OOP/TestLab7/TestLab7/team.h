//
//  team.hpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef team_h
#define team_h

#include <stdio.h>
#include <string>

class Teams{

private:
    std::string name;
    std::string country;
    int score;
    
public:
    Teams();
    Teams(std::string name,std::string country,int score);
    std::string getName()const{return name;}
    std::string getCountry()const{return country;}
    int getScore()const{return score;}
};

#endif /* team_hpp */
