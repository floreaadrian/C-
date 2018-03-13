#pragma once

typedef struct {
  char *name;
  char *continent;
  int population;
} Country;

Country *createCountry(char *name, char *continent, int population);
void destroyCountry(Country *country);
Country *copyCountry(Country *co);

char *getName(Country *co);
char *getContinent(Country *co);
int getPopulation(Country *co);
void toString(Country *co, char str[]);
