//
//  UI.hpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef UI_h
#define UI_h

#include <stdio.h>
#include "controller.h"

class UI{
private:
    Controller ctrl;
public:
    UI(const Controller &c) : ctrl(c){};
    void start();
    void printMenu();
    void addFunc();
    void printSorted();
    void pairTeams();
};

#endif /* UI_hpp */
