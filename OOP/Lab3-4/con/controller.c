#include "controller.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Controller* createController(Repo* r)
{
	//creating the controller by allocating memory
	Controller* c = (Controller*)malloc(sizeof(Controller));
	//making the repository of the controller the repository we gave
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
	//we create a country to add
	Country* co = createCountry(name, continent, population);
	/*
		In p we got one of this values:
			1-if the adding of of the country succeded
			0-if the adding of the country failed
	*/
	int p = addCountry(c->repo, co);
	//we destroy the country because we have a copy of it in the repository(if the adding was sucsesfull)
	destroyCountry(co);
	return p;
}

int deleteCountryCtrl(Controller* c, char* name)
{
	//we delete a country by name if we can
	//return 1 if the delete was sucsesfull
	//return 0 if the delete failed
	return deleteCountry(c->repo,name);
}

int updateCountryCtrl(Controller *c, char *name, char *newName, char *newContinent, int newPopulation)
{
	//we update a country by name if we can
	//return 1 if the update was sucsesfull
	//return 0 if the update failed
	return updateCountry(c->repo,name,newName,newContinent,newPopulation);
}

Repo* getRepoString(Controller* c,char what[])
{
	//we create a repository in which we save the countries who fulfill the condition
	Repo* res = createRepo();
	//we loop through the countries of our repository
	for (int i = 0; i < getRepoLength(c->repo); i++)
	{
		Country* co = getCountryOnPos(c->repo, i);
		//we verify if they have a common string
		if (strstr(getName(co), what) != NULL)
		{
			//we create a new country for store
			Country* newCountry = createCountry(co->name, co->continent, co->population);
			//we store our new country in the repository created at first
			addCountry(res, newCountry);
			//we delete the country because we have a copy of it in the repository
			destroyCountry(newCountry);
		}
	}
	//we print the number of found countries with the string
	printf("We found %d\n countries with this string\n",getRepoLength(res));
	//we return the created repo
	return res;
}

//we return a repo from a given controller
Repo* getRepo(Controller* c)
{
	return c->repo;
}
