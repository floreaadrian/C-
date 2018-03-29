//
//  main.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Tutorial.h"
#include "UI.h"

using namespace std;

int main(int argc, const char *argv[]) {
  Repository repo{};

  // add some Tutorials
  Tutorial s1{"Derek Banas", "C++ Programming", Duration{70, 32}, 0,
              "https://www.youtube.com/watch?v=Rub-JsjMhWY"};
  Tutorial s2{"Gleesik ", "#01 Tutorial C++ |Introducere +Visual Studio |Gleesik™", Duration{14, 6}, 0,
                              "https://www.youtube.com/watch?v=lAvIuQIhbOQ"};
  Tutorial s3{"TheChernoProject",
              "How C++ Works", Duration{20, 20}, 0,
              "https://www.youtube.com/watch?v=SfGuIVzE_Os"};
  Tutorial s4{"Easy Programming",
              "C++ Tutorials From Basic to Advance", Duration{553, 4}, 0,
              "https://www.youtube.com/watch?v=mUQZ1qmKlLY"};
  Tutorial s5{"Videotutorial.ro",
              "Introducere în programare -tutorial C++ -cursul 1", Duration{15, 52}, 0,
                           "https://www.youtube.com/watch?v=JjY9U9lu37I"};
  Tutorial s6{"thenewboston",
              "Buckys C++ Programming Tutorials -38 -Introduction to Pointers", Duration{6, 7}, 0,
                  "https://www.youtube.com/watch?v=Fa6S8Pz924k"};
  Tutorial s7{"Jerry Banfield", "Start C++ ProgrammingToday !", Duration{378, 23}, 0,
                     "https://www.youtube.com/watch?v=GNxVXPPZS_w"};
  Tutorial s8{"ProgrammingKnowledge", "C++ Tutorial |Learn C++ programming", Duration{756, 20}, 0,
              "https://www.youtube.com/watch?v=MhYECGUzdA4"};
  Tutorial s9{"ProgrammingKnowledge",
              "C Programming Tutorial |Learn C programming |C language", Duration{260, 20}, 0,
                             "https://www.youtube.com/watch?v=-CpG3oATGIs"};
  Tutorial s10{"thenewboston ",
               "Buckys C++ Programming Tutorials -12 -Introduction to Classes andObjects", Duration{8, 25}, 0,
                           "https://www.youtube.com/watch?v=ABRP_5RYhqU"};
  repo.addTutorial(s1);
  repo.addTutorial(s2);
  repo.addTutorial(s3);
  repo.addTutorial(s4);
  repo.addTutorial(s5);
  repo.addTutorial(s6);
  repo.addTutorial(s7);
  repo.addTutorial(s8);
  repo.addTutorial(s9);
  repo.addTutorial(s10);
    repo.tests();
  Controller ctrl{repo};
  UI ui{ctrl};
  ui.run();
  return 0;
}
