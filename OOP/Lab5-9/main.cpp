//
//  main.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Tutorial.h"
#include "TutorialValidator.h"
#include "RepositoryExceptions.h"
#include "UI.h"
#include "CSVWatchlist.h"
#include "HTMLWatchlist.h"


using namespace std;

 void tests() {
   Repository repo{"RepoTest.txt"};
   repo.tests();
   Watchlist watch{};
   watch.tests();
   FileWatchlist* fl = new CSVWatchlist{"WatchTest.txt"};
   Controller ctrl{repo,fl,TutorialValidator{}};
   ctrl.tests();
   Tutorial tutorial{};
   tutorial.tests();
   TutorialValidator val{};
   val.tests();
 }

int main(int argc, const char *argv[])
{
 // tests();
  try
  {
    Repository repo{"Repo.txt"};
    FileWatchlist* watch = nullptr;
    std::cout<<"CVS or HTML: ";
    string fileType{};
    std::cin >> fileType;
    if(fileType == "CVS")
      watch = new CSVWatchlist{"Watch.csv"};
    else
      watch = new HTMLWatchlist{"Watch.html"};
    Controller ctrl{repo, watch, TutorialValidator{}};
    UI ui{ctrl};
    ui.run();
  }
  catch (FileException &)
  {
    cout << "Repository file could not be opened! The application will terminate." << endl;
    return 1;
  }

  return 0;
}