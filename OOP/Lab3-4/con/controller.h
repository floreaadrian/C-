#pragma once
#include "../repo/repo1.h"

typedef struct {
  Repo *repo;
} Controller;

Controller *createController(Repo *r);
void destroyController(Controller *c);

int addCountryCtrl(Controller *c, char *name, char *continent, int population);
int deleteCountryCtrl(Controller *c, char *name);
int updateCountryCtrl(Controller *c, char *name, char *newName,
                      char *newContinent, int newPopulation);

Repo *getRepo(Controller *c);
Repo *getRepoString(Controller *c, char what[]);
