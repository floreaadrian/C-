//
//  UI.h
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#ifndef UI_h
#define UI_h

#include <stdio.h>
#include "Controller.h"

class UI{
private:
    Controller ctrl;
public:
    UI(const Controller& c) : ctrl(c) {}
    void run();
    void printMenu();
    void addUi();
    void movePainting();
    void showGallery();
    void undo();
};

#endif /* UI_h */
