//
//  main.cpp
//  TestLab7
//
//  Created by Adrian-Paul Florea on 4/19/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include <iostream>
#include "UI.h"

void tests(){
    Repository repo{};
    repo.tests();
    Controller ctrl{repo};
    ctrl.tests();
}

int main() {
    // insert code here...
    tests();
    Repository repo{};
    Controller ctrl{repo};
    ctrl.addCtrl("a", "romania");
    ctrl.addCtrl("b", "elvetia");
    ctrl.addCtrl("c", "romania");
    ctrl.addCtrl("d", "ghana");
    ctrl.addCtrl("e", "romania");
    UI ui{ctrl};
    ui.start();
    //std::cout << "Hello, World!\n";
    return 0;
}
