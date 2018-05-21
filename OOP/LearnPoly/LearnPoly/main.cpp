//
//  main.cpp
//  LearnPoly
//
//  Created by Adrian-Paul Florea on 5/16/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include <iostream>
#include "UI.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Person p{"Adrian"};
    Controller ctrl{p};
    UI ui{ctrl};
    ui.run();
    return 0;
}
