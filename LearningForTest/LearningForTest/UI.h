//
//  UI.hpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
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
    
    UI(const Controller &c) : ctrl(c) {}

    void run();
    void print();
private:
    static void printMenu();
    void add();
    void deleteObj();
    void update();
    void printObj();
    void sortObj();
};

#endif /* UI_hpp */
