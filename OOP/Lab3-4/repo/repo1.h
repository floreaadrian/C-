#pragma once
#include "../Array/array.h"
#include "../domain/domain.h"

typedef struct {
  Arrays *countries;
} Repo;

Repo *createRepo();
void destroyRepo(Repo *v);
Country *find(Repo *v, char *name);
int findPosOfCountry(Repo *v, char *name);
int checkContinent(char *conti);

int getRepoLength(Repo *v);
Country *getCountryOnPos(Repo *v, int pos);

int addCountry(Repo *v, Country *p);
int deleteCountry(Repo *v, char *name);
int updateCountry(Repo *v, char *name, char *newName, char *newContinent,
                  int newPopulation);
