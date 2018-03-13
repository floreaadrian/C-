#include "controller.h"
#include <stdlib.h>
#include <string.h>

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

	if (res == 1) // if the Country was successfully added - get rid of it from the memory
	{
        // destroy the Country that was just created, as the repository stored a copy
    	destroyCountry(co);
	}

	return res;
}

Repo* getRepoString(Controller* c)
{
	return c->repo;
}


Repo* getRepo(Controller* c)
{
	return c->repo;
}
