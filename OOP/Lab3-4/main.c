#include <stdio.h>
#include "ui/UI.h"

int main(){
	Repo* repo = createRepo(); //we create a reop for the controller
	Controller* ctrl = createController(repo); // we create a controller for the ui

	//we add some countries to have at the beging of the program
	addCountryCtrl(ctrl, "Romania", "Europa", 19);
	addCountryCtrl(ctrl, "Mexic", "America", 250);
	addCountryCtrl(ctrl, "China", "Asia", 1600);
	addCountryCtrl(ctrl, "Ghana", "Africa", 30);

	//we create the ui
	UI* ui = createUI(ctrl);

	//we start the ui
	startUI(ui);

	//we destroy the ui
	destroyUI(ui);

    return 0;
}
