#include "repo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Repo* createRepo()
{
	Repo* v = (Repo*)malloc(sizeof(Repo)); //allocating the space for the repository
	v->countries = createArrays(2); //creating the dynamic array for the repository
	return v;
}

void destroyRepo(Repo* v)
{
	if (v == NULL)
		return;
	destroy(v->countries); //we first need to destroy all the countries from our dynamic array
	free(v);//we destroy the repository
}

int findPosOfCountry(Repo * v, char * name)
{
	//we can't search a repository if we don't have one
	if (v == NULL)
		return -1;
	//we go through all of the countries int the repository
	for (int i = 0; i < getLength(v->countries); i++)
	{
		//we get a copy of a country
		Country* p = getCountry(v->countries, i);
		//if we found a country by name we return it's position
		if (strcmp(p->name, name) == 0)
			return i;
	}
	return -1;
}

Country* find(Repo* v, char* name)
{
	//we can't search a repository if we don't have one
	if (v == NULL)
		return NULL;
	//we first search through the repository
	int pos = findPosOfCountry(v, name);
	//if we didn't recive a position it means that we don't have such a country
	if (pos == -1)
		return NULL;
	//we return the country we found from the position we got
	return getCountry(v->countries, pos);
}

int addCountry(Repo* v, Country* co)
{
	if (v == NULL)
		return 0;

	// first search for a Country with the same name as the one that is to be added and do not add it if it already exists
	if (find(v, co->name) != NULL)
		return 0;
	//we verify if the continent is correct
    if (checkContinent(co->continent) == -1)
        return 0;
	//we verify if the population is bigger than 0
	if(co->population<=0)
		return 0;
	// a copy of the Country which was passed will be stored, such that the memory for the Country can be deallocated where it was allocated (in Controller)
	// and the Repository will handle its own memory
	Country* copy = copyCountry(co);
	addToArray(v->countries, copy);

	return 1;
}

//return 1 if it is a valid contintn and 0 otherwise
int checkContinent(char* conti)
{
	//we hand coded the check for each continent
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

int updateCountry(Repo *v, char* name, char* newName, char* newContinent, int newPopulation){
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
	//we make a copy of the country
    Country* co = getCountry(v->countries, pos);
	//we verify which atributes we need to change
	if(strcmp(newName,"null")==0)
        strcpy(newName,co->name);
    if(strcmp(newContinent,"null")==0)
        strcpy(newContinent,co->continent);
    if(newPopulation==-1)
        newPopulation=co->population;
	//we verify if the changed continent is valid
    pos = checkContinent(newContinent);
    	if (pos == -1)
    		return 0;
	//we delete the old country
    deleteCountry(v,name);
	//we create a new one
    co = createCountry(newName, newContinent, newPopulation);
	//we add the country and get ok which is 1 adding was succsesfull and 0 otherwise
	int ok = addCountry(v,co);
	//we destroy the country because we already have a copy of it in the repository
	destroyCountry(co);
	return ok;
}

int getRepoLength(Repo* v)
{
	if (v == NULL)
		return -1;
	//we return the length of a certain array
	return getLength(v->countries);
}

Country* getCountryOnPos(Repo* v, int pos)
{
	if (v == NULL)
		return NULL;
	//we verify if the position is corect
	if (pos < 0 || pos >= getLength(v->countries))
		return NULL;
	//we return a country from a certain position
	return getCountry(v->countries, pos);
}


// Tests
void testAdd()
{
	Repo* r = createRepo();

	Country* c1 = createCountry("Romania", "Europa", 19);
	addCountry(r, c1);
	assert(getRepoLength(r) == 1);
	assert(strcmp(getName(getCountryOnPos(r, 0)), "Romania") == 0);

	Country* c2 = createCountry("Uganda", "Africa", 41);
	assert(addCountry(r, c2) == 1);
	assert(getRepoLength(r) == 2);

	// now try to add the same Country again -> add must return 0
	assert(addCountry(r, c2) == 0);

	// destroy the test repository
	destroyRepo(r);

	// now the memory allocated for the countries must be freed
	destroyCountry(c1);
	destroyCountry(c2);
}

void testDelete()
{
	Repo* r = createRepo();

	Country* c1 = createCountry("Romania", "Europa", 19);
	addCountry(r, c1);
	Country* c2 = createCountry("Uganda", "Africa", 41);
	addCountry(r, c2);
	assert(getRepoLength(r) == 2);
	assert(deleteCountry(r,"Romania")==1);
	assert(getRepoLength(r) == 1);
	assert(deleteCountry(r,"France")==0);
	// destroy the test repository
	destroyRepo(r);
	// now the memory allocated for the countries must be freed
	destroyCountry(c1);
	destroyCountry(c2);
}

void testUpdate()
{
	Repo* r = createRepo();

	Country* c1 = createCountry("Romania", "Europa", 19);
	addCountry(r, c1);
	Country* c2 = createCountry("Uganda", "Africa", 41);
	addCountry(r, c2);
	assert(getRepoLength(r) == 2);
	assert(updateCountry(r,"Romania","Elvetia","null",-1)==1);
	assert(getRepoLength(r) == 1);
	assert(updateCountry(r,"Uganda","Romania","null",32)==0);
	// destroy the test repository
	destroyRepo(r);
	// now the memory allocated for the countries must be freed
	destroyCountry(c1);
	destroyCountry(c2);
}

void testsRepo()
{
	testAdd();
	testDelete();
//	testUpdate();
}
