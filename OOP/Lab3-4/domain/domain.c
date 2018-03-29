#include "domain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Country *createCountry(char *name, char *continent, int population) {
  Country *country = (Country *)malloc(
      sizeof(Country)); // we allocate the memory for the country
  country->name =
      (char *)malloc(sizeof(char) * strlen(name) +
                     1); // we allocate the memory for the name of the country
  strcpy(country->name,
         name); // we copy the name of the country into the country
  country->continent =
      (char *)malloc(sizeof(char) * strlen(continent) +
                     1); // we allocate the memory for the name of the continent
  strcpy(country->continent,
         continent); // we copy the continent of the country into the country
  country->population =
      population; // we copy the population of the country into the country
  return country; // returning a pointer to the country
}

Country *copyCountry(Country *co) {
  // we couldn't copy a country
  if (co == NULL)
    return NULL;
  // we create a new country
  Country *newCountry =
      createCountry(getName(co), getContinent(co), getPopulation(co));
  return newCountry;
}

void destroyCountry(Country *co) {
  if (co == NULL)
    return;
  // free the memory which was allocated for the component fields
  free(co->name);
  free(co->continent);
  // free the memory which was allocated for the planet structure
  free(co);
}

// we return the name of a certain country
char *getName(Country *co) { return co->name; }

// we return the continent of a certain country
char *getContinent(Country *co) { return co->continent; }

// we return the population of a certain country
int getPopulation(Country *co) { return co->population; }

// we print the information of the country in a nice way
void toString(Country *co, char str[]) {
  sprintf(str,
          "Country %s is on the %s continent and its population is %d million.",
          co->name, co->continent, co->population);
}
