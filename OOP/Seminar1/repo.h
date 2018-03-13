#pragma once
#include "planet.h"

typedef struct {
	Planet* vect[100];
	int lenght;
}PlanetRepo;

PlanetRepo *createRepo();
void destroryRepo(PlanetRepo *p);
void addPlanet(Planet *planet,PlanetRepo *p);

