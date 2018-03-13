#include <stdio.h>
#include "ui/UI.h"

int main(){
	Repo* repo = createRepo();
	Controller* ctrl = createController(repo);

	addCountryCtrl(ctrl, "Romania", "Europa", 19);
	addCountryCtrl(ctrl, "Mexic", "America", 250);
	addCountryCtrl(ctrl, "China", "Asia", 1600);
	addCountryCtrl(ctrl, "Ghana", "Africa", 30);

	UI* ui = createUI(ctrl);

	startUI(ui);

	destroyUI(ui);

    return 0;
}
