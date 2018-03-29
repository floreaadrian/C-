#include "ui/UI.h"
#include <stdio.h>

int main() {
  testsRepo();
  testsDynamicArray();
  testsStack();
  // we create a reop for the controller
  Repo *repo = createRepo();
  // we create a stack for undo/redo
  OperationsStack *operationsStackUndo = createStack();
  OperationsStack *operationsStackRedo = createStack();
  Controller *ctrl =
      createController(repo, operationsStackUndo, operationsStackRedo);

  // we add some countries to have at the beging of the program
  addCountryCtrl(ctrl, "Romania", "Europa", 19);
  addCountryCtrl(ctrl, "Mexic", "America", 250);
  addCountryCtrl(ctrl, "China", "Asia", 1600);
  addCountryCtrl(ctrl, "Ghana", "Africa", 30);
  addCountryCtrl(ctrl, "India", "Asia", 30);

  // we create the ui
  UI *ui = createUI(ctrl);

  // we start the ui
  startUI(ui);

  // we destroy the ui
  destroyUI(ui);

  return 0;
}
