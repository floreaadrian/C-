#include "planet.h"
#include <string.h>
#include <stdlib.h>

Planet * create_planet(char *name,char *type,double distance){
	Planet *planet= (Planet *)malloc(sizeof(Planet));
	planet->name =(char *)malloc(sizeof(char)*(strlen(name))+1);
	strcpy(planet->name,name);
	planet->type =(char *)malloc(sizeof(char)*(strlen(name))+1);
	strcpy(planet->type,type);
	planet->distance = distance;
    return planet;
}


void destroy_planet(Planet *planet)
{
	free(planet->type);
	free(planet->name);
//	free(&planet->distance);
    free(planet);
}

char *get_name(Planet *planet){
    return planet->name;
}
