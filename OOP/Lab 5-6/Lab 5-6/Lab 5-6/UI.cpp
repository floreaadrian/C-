//
//  UI.cpp
//  Lab 5-6
//
//  Created by Adrian-Paul Florea on 3/25/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "UI.h"
#include "sha256.h"
#include <string>

using namespace std;

void UI::printMenu() {
  cout << '\n';
  cout << "1 - Manage Tutorial repository.\n";
  cout << "2 - Manage playlist.\n";
  cout << "0 - Exit.\n";
}

void UI::printRepositoryMenu() {
  cout << "Possible commands: \n";
  cout << "\t 1 - Add Tutorial.\n";
  cout << "\t 2 - Delete Tutorial.\n";
  cout << "\t 3 - Update Tutorial.\n";
  cout << "\t 4 - Display all.\n";
  cout << "\t 0 - Back.\n";
}

void UI::printWatchListMenu() {
  cout << "Possible commands: \n";
  cout << "\t 1 - See tutorials by presenter and play.\n";
  cout << "\t 2 - Add the active tutorial to the watchlist.\n";
  cout << "\t 3 - Next tutorial.\n";
  cout << "\t 4 - Delete tutorial.\n";
  cout << "\t 5 - See all the tutorials in the watchlist.\n";
  cout << "\t 0 - Back.\n";
}

void UI::addTutorialToRepo() {
  cout << "Enter the presenter: ";
  std::string presenter;
  getline(cin, presenter);
  cout << "Enter the title: ";
  std::string title;
  getline(cin, title);
  double minutes = 0, seconds = 0;
  cout << "Enter the duration: \n";
  cout << "\tMinutes: ";
  cin >> minutes;
  cin.ignore();
  cout << "\tSeconds: ";
  cin >> seconds;
  cin.ignore();
  cout << "Youtube link: ";
  std::string link;
  getline(cin, link);
  int likes = 0;
  int res = this->ctrl.addTutorialToRepository(presenter, title, minutes,
                                               seconds, likes, link);
  if (res == 1)
    printf("Succsesful add!\n");
  else
    printf("Failed add!\n");
}

void UI::deleteTutorial(int option) {
  cout << "Enter the presenter: ";
  std::string presenter;
  getline(cin, presenter);
  cout << "Enter the title: ";
  std::string title;
  getline(cin, title);
  int res = 0;
  if (option == 1)
    res = this->ctrl.deleteTutorialToRepository(presenter, title);
  else {
    cout << "If you liked the tutorial enter 1,otherwise enter 0: ";
    int option;
    cin >> option;
    bool ok;
    if (option == 0)
      ok = false;
    else
      ok = true;
    res = this->ctrl.deleteTutorialWatchlistNameAndPresenterCtrl(presenter,
                                                                 title, ok);
  }
  if (res == 1)
    printf("Succsesful delete!\n");
  else
    printf("Failed delete!\n");
}

void UI::updateTutorialToRepo() {
  cout << "Enter the presenter: ";
  std::string presenter;
  getline(cin, presenter);
  cout << "Enter the title: ";
  std::string title;
  getline(cin, title);
  cout << "Enter the new presenter: ";
  std::string newPresenter;
  getline(cin, newPresenter);
  cout << "Enter the new title: ";
  std::string newTitle;
  getline(cin, newTitle);
  double minutes = 0, seconds = 0;
  cout << "Enter the new duration: \n";
  cout << "\tMinutes: ";
  cin >> minutes;
  cin.ignore();
  cout << "\tSeconds: ";
  cin >> seconds;
  cin.ignore();
  cout << "New youtube link: ";
  std::string link;
  getline(cin, link);
  int likes = 0;
  int res = this->ctrl.updateTutorialToRepository(
      presenter, title, newPresenter, newTitle, minutes, seconds, likes, link);
  if (res == 1)
    printf("Succsesful update!\n");
  else
    printf("Failed update!\n");
}

void UI::displayAllTutorials(int option) {
  DynamicArray v = this->ctrl.getRepo().getTutorials();
  if (option == 2)
    v = this->ctrl.getWatchlist().getTutorials();
  Tutorial *Tutorials = v.getAllElems();
  if (Tutorials == NULL)
    return;
  if (v.getSize() == 0) {
    cout << "There are no Tutorials in the repository.\n";
    return;
  }

  for (int i = 0; i < v.getSize(); i++) {
    Tutorial s = Tutorials[i];
    Duration d = s.getDuration();
    for (int j = 0; j < 30; j++)
      cout << "-";
    cout << "\n";
    cout << s.getPresenter() << " - " << s.getTitle() << " \n"
         << d.getMinutes() << ":" << d.getSeconds()
         << "\nLikes: " << s.getLikes() << '\n';
  }
  for (int j = 0; j < 30; j++)
    cout << "-";
  cout << "\n";
}

void UI::addAllTutorialsByPresentersToWatchlist() {
  cout << "Enter the presenter: ";
  std::string presenter;
  getline(cin, presenter);
  this->ctrl.addAllTutorialsByPresenterToWatchlist(presenter);
  this->displayAllTutorials(2);
}

void UI::run() {
  while (true) {
    UI::printMenu();
    int command{0};
    cout << "Input the command: ";
    cin >> command;
    cin.ignore();
    if (command == 0)
      break;

    // repository management
    if (command == 1) {
      string pass;
      cout << "Input the password: ";
      cin >> pass;
      pass = sha256(pass);
      if (pass ==
          "5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8")
        while (true) {
          UI::printRepositoryMenu();
          int commandRepo{0};
          cout << "Input the command: ";
          cin >> commandRepo;
          cin.ignore();
          if (commandRepo == 0)
            break;
          switch (commandRepo) {
          case 1:
            this->addTutorialToRepo();
            break;
          case 2:
            this->deleteTutorial(1);
            break;
          case 3:
            this->updateTutorialToRepo();
            break;
          case 4:
            this->displayAllTutorials(1);
          }
        }
      else
        cout << "Invalid password!";
    } else if (command == 2) {
      while (true) {
        UI::printWatchListMenu();
        int commandWatchlist{0};
        cout << "Input the command: ";
        cin >> commandWatchlist;
        cin.ignore();
        if (commandWatchlist == 0)
          break;
        switch (commandWatchlist) {
        case 1:
          // see by presenter and play
          this->addAllTutorialsByPresentersToWatchlist();
          this->ctrl.playWatchlist();
          break;
        case 2: {
          // Add the active tutorial to the watchlist.\n";
          this->ctrl.nextTutorialWatchlist();
          Tutorial s = this->ctrl.getWatchlist().getCurrentTutorial();
          cout << "Now playing: " << s.getPresenter() << " - " << s.getTitle()
               << "\n";
          break;
        }
        case 3: {
          // cout << "\t 3 - Next tutorial.\n";
          this->ctrl.deleteTutorialWatchlist(
              this->ctrl.getWatchlist().getCurrentTutorial());
          this->ctrl.playWatchlist();
          Tutorial s = this->ctrl.getWatchlist().getCurrentTutorial();
          cout << "Now playing: " << s.getPresenter() << " - " << s.getTitle()
               << "\n";
          break;
        }
        case 4: {
          // Delete tutorial from watchlist
          this->deleteTutorial(2);
          break;
        }
        case 5: {
          displayAllTutorials(2);
          break;
        }
        }
      }
    }
  }
}
