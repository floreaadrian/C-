//
//  main.cpp
//  LearningForTest
//
//  Created by Adrian-Paul Florea on 4/10/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include <iostream>
#include "UI.h"

int main() {
    Repository repo{};
    Controller ctrl {repo};
    UI ui{ctrl};
    ui.run();
    return 0;
}
