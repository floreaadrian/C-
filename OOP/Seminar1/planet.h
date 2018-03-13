#pragma once

typedef struct {
  char *name;
  char *type;
  double distance;
} Planet;

Planet *create_planet(char *name, char *type, double distance);
void destroy_planet(Planet *planet);

char *get_name(Planet *planet);
