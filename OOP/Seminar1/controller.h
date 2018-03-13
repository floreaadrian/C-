#pragma once
#include "PlanetRepo.h"


typedef struct{
	PlanetRepo* repo;
}Controller;

Controller* createController(PlanetRepo*);
void destroyController(Controller*);
void addPlanetCtrl(Controller* ctrl,Planet* p);


