#pragma once
#include "../Array/array.h"
#include "../domain/domain.h"

typedef struct {
  Arrays *countrys;
} Repo;

Repo *createRepo();
void destroyRepo(Repo *v);
Country *find(Repo *v, char *name);
int checkContinent(char *conti);
int findPosOfCountry(Repo *v, char *name);
int addCountry(Repo *v, Country *p);
void deleteCountry(Repo *v, char *name);
int getRepoLength(Repo *v);
Country *getCountryOnPos(Repo *v, int pos);
