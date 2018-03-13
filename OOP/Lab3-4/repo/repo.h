#pragma once
#include "../Array/array.h"
#include "../domain/domain.h"

typedef struct {
  Arrays *countries; // we define our dynamic arrays
} Repo;

Repo *createRepo();                        // we create a repo
void destroyRepo(Repo *v);                 // we destroy a certain repo
Country *find(Repo *v, char *name);        // returns a country if found by name
int findPosOfCountry(Repo *v, char *name); // returns a position of a country if
                                           // found, otherwise returns -1

int checkContinent(char *conti); // verifies if a certain input is a continent

int getRepoLength(Repo *v); // returning the repository length
Country *
getCountryOnPos(Repo *v,
                int pos); // returning a countri from a certain position

// all of these 3 function retuns 1 if the succeded an 0 if they failed
int addCountry(Repo *v, Country *p);    // adding a country to a repository
int deleteCountry(Repo *v, char *name); // deleting a country from a repository
int updateCountry(Repo *v, char *name, char *newName, char *newContinent,
                  int newPopulation); // updating a country from a repository
