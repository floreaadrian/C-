#pragma once
#include "../con/controller.h"

typedef struct {
  Controller *ctrl; // we define the controller for the ui
} UI;

UI *createUI(Controller *c); // we create a ui
void destroyUI(UI *ui);      // we destroy a ui

void startUI(UI *ui); // we start a ui(for the main function)
