#pragma once
#include "controller.h"

Controller *crateController(PlanetRepo *repo)
{
	controller* ctrl = (Controller*)malloc(sizeof(Controller));
	ctrl->repo=r;
	return ctrl;
}

void destroyRepo(Controller *ctrl)


