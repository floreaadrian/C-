#include "repo.h"
#include <stdlib.h>

PlanetRepo *createRepo()
{
	PlanetRepo *planets=(PlanetRepo*)malloc(sizeof(PlanetRepo));
	planets->lenght =0;
	return planets;
}

void destroyRepo(PlanetRepo *p)
{
	for(int i=0;i<p->lenght;i++)
	{
		destroy_planet(p->vect[i]);
	}
	free(p);
}

void addPlanet(Planet *p,PlanetRepo *planetRepo)
{
	planetRepo->vect[planetRepo->lenght]=p;
	planetRepo->lenght++;	
}
