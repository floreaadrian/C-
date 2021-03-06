#pragma once
#include "../repo/repo.h"
#include "../stack/stack.h"

typedef struct {
  Repo *repo; // we create a repository into the controller
  OperationsStack *undoStack;
  OperationsStack *redoStack;
} Controller;

Controller *createController(
    Repo *r, OperationsStack *undoS,
    OperationsStack *redoS); // we create a controller with a given repository
void destroyController(Controller *c); // we destroy a given controller

// all of these 3 function retuns 1 if the succeded an 0 if they failed
int addCountryCtrl(Controller *c, char *name, char *continent,
                   int population); // we add a country to the repo
int deleteCountryCtrl(
    Controller *c,
    char *name); // we delete a country from the repo of the controller
int updateCountryCtrl(
    Controller *c, char *name, char *newName, char *newContinent,
    int newPopulation); // we update a country from the repo of the controller

// getting a repo from the certain controller
Repo *getRepo(Controller *c);
// getting a repo that have all countries with a string what in them
Repo *getRepoBy(Controller *c, char what[], int option);
Repo *getRepoStringSorted(Controller *c, char what[], int optionFind,
                          int optionSort);

int undo(Controller *c);
int redo(Controller *c);
