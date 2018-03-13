#include "controller.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Controller* createController(Repo* r)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	return c;
}

void destroyController(Controller * c)
{
	// first destroy the repository inside
	destroyRepo(c->repo);
	// then free the memory
	free(c);
}

int addCountryCtrl(Controller* c, char* name, char* continent, int population)
{
	Country* co = createCountry(name, continent, population);

	int res = addCountry(c->repo, co);
	destroyCountry(co);
	return res;
}

int deleteCountryCtrl(Controller* c, char* name)
{
	return deleteCountry(c->repo,name);
}

int updateCountryCtrl(Controller *c, char *name, char *newName, char *newContinent, int newPopulation)
{
	return updateCountry(c->repo,name,newName,newContinent,newPopulation);
}

Repo* getRepoString(Controller* c,char what[])
{
	Repo* res = createRepo();
	for (int i = 0; i < getRepoLength(c->repo); i++)
	{
		Country* co = getCountryOnPos(c->repo, i);
		if (strstr(getName(co), what) != NULL)
		{
			Country* newCountry = createCountry(co->name, co->continent, co->population);
			addCountry(res, newCountry);
		}
	}
	printf("%d\n",getRepoLength(res));
	return res;
}


Repo* getRepo(Controller* c)
{
	return c->repo;
}
