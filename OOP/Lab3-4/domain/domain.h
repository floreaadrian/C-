#pragma once

typedef struct {
  char *name;      // pointer to the name of the country
  char *continent; // pointer to the continent of the country
  int population;  // population of the country
} Country;

Country *createCountry(char *name, char *continent,
                       int population); // creating country
void destroyCountry(Country *country);  // destroing a certain country
Country *copyCountry(Country *co);      // coping a country

char *getName(Country *co);
char *getContinent(Country *co);
int getPopulation(Country *co);
void toString(Country *co, char str[]);
