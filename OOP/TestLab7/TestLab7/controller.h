//
//  controller.hpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef controller_h
#define controller_h

#include <stdio.h>
#include <vector>
#include "repo.h"

class Controller{
private:
    Repository repo;
public:
    //Controller(const Repository &repo): {repo};
    Controller(const Repository &repo);
    int addCtrl(std::string name,std::string country);
    std::vector<Teams> getSorted();
    int pairTeams(std::string team1,std::string team2,std::string winning);
    void tests();
    void testAdd();
    void testSort();
};

#endif /* controller_hpp */
