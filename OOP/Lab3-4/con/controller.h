#pragma once
#include "../repo/repo1.h"

typedef struct {
  Repo *repo;
} Controller;

Controller *createController(Repo *r);
void destroyController(Controller *c);

int addCountryCtrl(Controller *c, char *name, char *continent, int population);

Repo *getRepo(Controller *c);
Repo *getRepoString(Controller *c);
