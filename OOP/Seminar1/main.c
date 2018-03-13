#include <stdio.h>
#include "planet.h"
#include "repo.h"

int main(){
    Planet *planet = create_planet("Romania","Europa",19);
    //printf("%s",get_name(planet));
    destroy_planet(planet);
    PlanetRepo *repository =createRepo();
    Planet *planet1 = create_planet("Venus","Nu",23.0);
    planet = create_planet("Romania","Europa",19);
    addPlanet(planet1,repository);
    int i;
    addPlanet(planet,repository);
    for(i=0;i<repository->lenght;i++)
    {
        printf("%s ",get_name(repository->vect[i]));
    }
    return 0;
}
