#include "repo1.h"
#include <stdlib.h>
#include <string.h>

Repo* createRepo()
{
	Repo* v = (Repo*)malloc(sizeof(Repo));
	v->countries = createArrays(2);
	return v;
}

void destroyRepo(Repo* v)
{
	if (v == NULL)
		return;
	destroy(v->countries);
	free(v);
}

int findPosOfCountry(Repo * v, char * name)
{
	if (v == NULL)
		return -1;
	for (int i = 0; i < getLength(v->countries); i++)
	{
		Country* p = getCountry(v->countries, i);
		if (strcmp(p->name, name) == 0)
			return i;
	}
	return -1;
}

Country* find(Repo* v, char* name)
{
	if (v == NULL)
		return NULL;

	int pos = findPosOfCountry(v, name);
	if (pos == -1)
		return NULL;
	return getCountry(v->countries, pos);
}

int addCountry(Repo* v, Country* co)
{
	if (v == NULL)
		return 0;

	// first search for a Country with the same name as the one that is to be added and do not add it if it already exists
	if (find(v, co->name) != NULL)
		return 0;
    if (checkContinent(co->continent) == -1)
        return 0;
	if(co->population<=0)
		return 0;
	// a copy of the Country which was passed will be stored, such that the memory for the Country can be deallocated where it was allocated (in Controller)
	// and the Repository will handle its own memory
	Country* copy = copyCountry(co);
	addToArray(v->countries, copy);

	return 1;
}

int checkContinent(char* conti)
{

    if(!strcmp(conti,"Europa") || !strcmp(conti,"Africa") || !strcmp(conti,"America") || !strcmp(conti,"Australia") || !strcmp(conti,"Asia"))
        return 1;
    return -1;
}

int deleteCountry(Repo* v, char* symbol)
{
	if (v == NULL)
		return 0;

	// find the position of the Country in the repository
	int pos = findPosOfCountry(v, symbol);
	if (pos == -1)
		return 0;

	// destroy the Country
	Country* co = getCountry(v->countries, pos);
	destroyCountry(co);

	// delete the pointer from the dynamic array
	delete(v->countries, pos);
    return 1;
}

int updateCountry(Repo *v, char *name, char *newName, char *newContinent, int newPopulation){
    if (v == NULL)
		return 0;

	// find the position of the Country in the repository
	int pos = findPosOfCountry(v, name);
	if (pos == -1)
		return 0;
    //if we don't find a contry with the same name as our newName we can continue
	int posNew = findPosOfCountry(v, newName);
	if (posNew != -1)
		return 0;

    Country* co = getCountry(v->countries, pos);
    if(strcmp(newName,"null")==0)
        strcpy(newName,co->name);
    if(strcmp(newContinent,"null")==0)
        strcpy(newContinent,co->continent);
    if(newPopulation==-1)
        newPopulation=co->population;

    pos = checkContinent(newContinent);
    	if (pos == -1)
    		return 0;
    deleteCountry(v,name);
    co = createCountry(newName, newContinent, newPopulation);
    int ok = addCountry(v,co);
	destroyCountry(co);
	return ok;
}

int getRepoLength(Repo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->countries);
}

Country* getCountryOnPos(Repo* v, int pos)
{
	if (v == NULL)
		return NULL;

	if (pos < 0 || pos >= getLength(v->countries))
		return NULL;

	return getCountry(v->countries, pos);
}
