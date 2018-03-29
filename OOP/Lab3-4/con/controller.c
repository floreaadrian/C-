#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Controller *createController(Repo *r, OperationsStack *undoS,
                             OperationsStack *redoS) {
  // creating the controller by allocating memory
  Controller *c = (Controller *)malloc(sizeof(Controller));
  // making the repository of the controller the repository we gave
  c->repo = r;
  c->undoStack = undoS;
  c->redoStack = redoS;
  return c;
}

void destroyController(Controller *c) {
  // first destroy the repository inside
  destroyRepo(c->repo);
  // then free the memory
  destroyStack(c->undoStack);
  destroyStack(c->redoStack);
  free(c);
}

int addCountryCtrl(Controller *c, char *name, char *continent, int population) {
  // we create a country to add
  Country *co = createCountry(name, continent, population);
  /*
          In p we got one of this values:
                  1-if the adding of of the country succeded
                  0-if the adding of the country failed
  */
  int p = addCountry(c->repo, co);
  if (p == 1) // if the planet was successfully added - register the operation
  {
    Operation *o = createOperation(co, NULL, "add");
    push(c->undoStack, o);
    // once added, the operation can be destroyed (a copy of the operation was
    // added)
    destroyOperation(o);
  }
  // we destroy the country because we have a copy of it in the repository(if
  // the adding was sucsesfull)
  destroyCountry(co);
  return p;
}

int deleteCountryCtrl(Controller *c, char *name) {
  // we delete a country by name if we can
  // return 1 if the delete was sucsesfull
  // return 0 if the delete failed
  Country *co = copyCountry(find(c->repo, name));
  int p = deleteCountry(c->repo, name);
  if (p == 1) // if the planet was successfully added - register the operation
  {
    Operation *o = createOperation(co, NULL, "delete");
    push(c->undoStack, o);
    // once added, the operation can be destroyed (a copy of the operation was
    // added)
    destroyOperation(o);
    destroyCountry(co);
  }
  return p;
}

int updateCountryCtrl(Controller *c, char *name, char *newName,
                      char *newContinent, int newPopulation) {
  // we update a country by name if we can
  // return 1 if the update was sucsesfull
  // return 0 if the update failed
  Country *co = copyCountry(find(c->repo, name));
  int p = updateCountry(c->repo, name, newName, newContinent, newPopulation);
  if (p == 1) // if the planet was successfully added - register the operation
  {
    Country *co1 = createCountry(newName, newContinent, newPopulation);
    Operation *o = createOperation(co, co1, "update");
    push(c->undoStack, o);
    // once added, the operation can be destroyed (a copy of the operation was
    // added)
    destroyOperation(o);
    destroyCountry(co);
    destroyCountry(co1);
  }
  return p;
}

void addForFind(Country *co, Repo *res) {
  // we create a new country for store
  Country *newCountry = createCountry(co->name, co->continent, co->population);
  // we store our new country in the repository created at first
  addCountry(res, newCountry);
  // we delete the country because we have a copy of it in the repository
  destroyCountry(newCountry);
}

Repo *getRepoBy(Controller *c, char what[], int option) {
  // we create a repository in which we save the countries who fulfill the
  // condition
  Repo *res = createRepo();
  // we loop through the countries of our repository
  for (int i = 0; i < getRepoLength(c->repo); i++) {
    Country *co = getCountryOnPos(c->repo, i);
    if (option == 1) {
      if (strstr(getName(co), what) != NULL)
        addForFind(co, res);
    } else if (option == 2) {
      if (strcmp(getContinent(co), what) == 0)
        addForFind(co, res);
    }
  }
  // we print the number of found countries with the string
  // we return the created repo
  return res;
}
Repo *getRepoStringSorted(Controller *c, char what[], int optionFind,
                          int optionSort) {
  Repo *res = getRepoBy(c, what, optionFind);
  return sortRepo(res, optionSort);
}

// we return a repo from a given controller
Repo *getRepo(Controller *c) { return c->repo; }

int undo(Controller *c) {
  if (isEmpty(c->undoStack)) {
    return 0;
  }

  Operation *operation = pop(c->undoStack);

  if (strcmp(getOperationType(operation), "add") == 0) {
    Country *country = getCountryStack(operation);
    Operation *o = createOperation(country, NULL, "add");
    push(c->redoStack, o);
    // once added, the operation can be destroyed (a copy of the operation was
    // added)
    destroyOperation(o);
    char name[50];
    strcpy(name, getName(country));
    deleteCountry(c->repo, name);
  } else if (strcmp(getOperationType(operation), "delete") == 0) {
    Country *country = getCountryStack(operation);
    Operation *o = createOperation(country, NULL, "delete");
    push(c->redoStack, o);
    // once added, the operation can be destroyed (a copy of the operation was
    // added)
    destroyOperation(o);
    addCountry(c->repo, country);
  } else if (strcmp(getOperationType(operation), "update") == 0) {
    Country *country = getCountryStack(operation);
    Country *country2 = getCountryStackUpdate(operation);
    Operation *o = createOperation(country, country2, "update");
    push(c->redoStack, o);
    // once added, the operation can be destroyed (a copy of the operation was
    // added)
    char name[50];
    strcpy(name, getName(country2));
    deleteCountry(c->repo, name);
    addCountry(c->repo, country);
    destroyOperation(o);
  }

  // the operation must be destroyed
  destroyOperation(operation);

  return 1;
}

int redo(Controller *c) {
  if (isEmpty(c->redoStack)) {
    return 0;
  }

  Operation *operation = pop(c->redoStack);

  if (strcmp(getOperationType(operation), "add") == 0) {
    Country *country = getCountryStack(operation);
    addCountry(c->repo, country);
  } else if (strcmp(getOperationType(operation), "delete") == 0) {
    Country *country = getCountryStack(operation);
    char name[50];
    strcpy(name, getName(country));
    deleteCountry(c->repo, name);
  } else if (strcmp(getOperationType(operation), "update") == 0) {
    Country *country = getCountryStack(operation);
    Country *country2 = getCountryStackUpdate(operation);
    char name[50];
    strcpy(name, getName(country));
    updateCountryCtrl(c, name, country2->name, country2->continent,
                      country2->population);
  }

  // the operation must be destroyed
  destroyOperation(operation);

  return 1;
}
