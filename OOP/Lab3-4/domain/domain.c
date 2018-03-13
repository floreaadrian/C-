#include "domain.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Country* createCountry(char *name,char *continent,int population){
    Country *country=(Country*)malloc(sizeof(Country));
    country->name = (char *)malloc(sizeof(char)*strlen(name)+1);
    strcpy(country->name,name);
    country->continent = (char *)malloc(sizeof(char)*strlen(continent)+1);
    strcpy(country->continent,continent);
    country->population=population;
    return country;
}


Country* copyCountry(Country* co)
{
	if (co == NULL)
		return NULL;
	Country* newCountry = createCountry(getName(co), getContinent(co), getPopulation(co));
	return newCountry;
}

void destroyCountry(Country* co)
{
	if (co == NULL)
		return;
	// free the memory which was allocated for the component fields
	free(co->name);
	free(co->continent);
	// free the memory which was allocated for the planet structure
	free(co);
}


char* getName(Country* co)
{
	return co->name;
}

char* getContinent(Country* co)
{
	return co->continent;
}

double getPopulation(Country* co)
{
	return co->population;
}


void toString(Country* co, char str[])
{
	sprintf(str, "Country %s is on the %s continent and its population is %d million.", co->name, co->continent,co->population);
}
