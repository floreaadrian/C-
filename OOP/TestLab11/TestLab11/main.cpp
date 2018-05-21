//
//  main.cpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include <iostream>
#include "UI.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Repository repoA{};
    Painting p{"a","b",1};
    Painting p1{"b","a",2};
    Painting p2{"c","b",3};
    repoA.addPaintintg(p);
    repoA.addPaintintg(p1);
    repoA.addPaintintg(p2);
    Repository repoS{};
    Controller ctrl{repoA,repoS};
    UI ui{ctrl};
    ui.run();
    return 0;
}
