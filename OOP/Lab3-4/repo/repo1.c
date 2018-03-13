#include "repo1.h"
#include <stdlib.h>
#include <string.h>

Repo* createRepo()
{
	Repo* v = (Repo*)malloc(sizeof(Repo));
	v->countrys = createArrays(2);
	return v;
}

void destroyRepo(Repo* v)
{
	if (v == NULL)
		return;
	destroy(v->countrys);
	free(v);
}

int findPosOfCountry(Repo * v, char * name)
{
	if (v == NULL)
		return -1;
	for (int i = 0; i < getLength(v->countrys); i++)
	{
		Country* p = getCountry(v->countrys, i);
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
	return getCountry(v->countrys, pos);
}

int addCountry(Repo* v, Country* co)
{
	if (v == NULL)
		return 0;

	// first search for a Country with the same name as the one that is to be added and do not add it if it already exists
	if (find(v, co->name) != NULL)
		return 0;
    if (checkContinent(co->continent) == 0)
        return 0;
	// a copy of the Country which was passed will be stored, such that the memory for the Country can be deallocated where it was allocated (in Controller)
	// and the Repository will handle its own memory
	Country* copy = copyCountry(co);
	addToArray(v->countrys, copy);

	return 1;
}

int checkContinent(char* conti)
{

    if(!strcmp(conti,"Europa") || !strcmp(conti,"Africa") || !strcmp(conti,"America") || !strcmp(conti,"Australia") || !strcmp(conti,"Asia"))
        return 1;
    return 0;
}

void deleteCountry(Repo* v, char* symbol)
{
	if (v == NULL)
		return;

	// find the position of the Country in the repository
	int pos = findPosOfCountry(v, symbol);
	if (pos == -1)
		return;

	// destroy the Country
	Country* p = getCountry(v->countrys, pos);
	destroyCountry(p);

	// delete the pointer from the dynamic array
	delete(v->countrys, pos);
}

int getRepoLength(Repo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->countrys);
}

Country* getCountryOnPos(Repo* v, int pos)
{
	if (v == NULL)
		return NULL;

	if (pos < 0 || pos >= getLength(v->countrys))
		return NULL;

	return getCountry(v->countrys, pos);
}
