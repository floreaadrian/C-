#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UI* createUI(Controller* c){
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;
	return ui;
}

void destroyUI(UI * ui){
	// first destroy the controller
	destroyController(ui->ctrl);
	// free the UI memory
	free(ui);
}

/*
	Prints the available menu for the problem
	Input: -
	Output: the menu is printed at the console
*/
void printMenu(){
    int i=0;
    printf("\n");
    for(i=0;i<30;++i)
    printf("*");
    printf("\n");
	printf("1 - Add a country.\n");
	printf("2 - Delete a country.\n");
	printf("3 - Update a country.\n");
	printf("4 - List countries with a given string.\n");
    printf("5 - List all the countries\n");
	printf("0 - Exit.\n");
    printf("\n");
    for(i=0;i<30;++i)
    printf("*");
    printf("\n");
}

/*
	Reads an integer number from the keyboard. Asks for number while read errors encoutered.
	Input: the message to be displayed when asking the user for input.
	Returns the number.
*/
int getInteger(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf("%s",message);
		scanf("%s", s);
		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

int getCmd() {
    int cmd = getInteger("Give command: ");
    if (cmd >=1 || cmd <=4)
        return cmd;
    return -1;
}

void readStringWithSpaces(const char* message, size_t maxStrSize, char str[])
{
	printf("%s\n",message);
	fgets(str, maxStrSize, stdin);
	// the newline is also read so we must eliminate it from the string
	int size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

void readString(const char* message,char str[])
{
    printf("%s",message);
    scanf("%s",str);
}

/*
	Reads a string with spaces from the standard input.
	Input:	message - string, message to be shown to the user.
			maxStrSize - the maximum size for the string to be read
	Output: the string that was read.
*/
int addCountryUI(UI* ui){
	// read the country's data
	char name[50], continent[50];
	int population;
	readString("Please input the name: ", name);
    readString("Please input the continent: ",continent);
	printf("Please input the population: ");
	scanf("%d", &population);

	return addCountryCtrl(ui->ctrl, name, continent, population);
}

int deleteCountryUI(UI* ui){
	// read the name of the country to be deleted
	char name[50];
	readString("Please input the name of country you want to delete: ", name);

	return deleteCountryCtrl(ui->ctrl, name);
}

int updateCountryUI(UI* ui){
    char name[50],newName[50],newContinent[50];
    printf("If you don't want to modify the name or the continent write null in either case\n");
    printf("If you don't want to change the population write -1 when it comes up\n");
    readString("Please input the name of the country you want to update: ", name);
    readString("Please input the new name: ", newName);
    readString("Please input the new continent: ", newContinent);
    int newPopulation=getInteger("Please input the new population: ");
    return updateCountryCtrl(ui->ctrl,name,newName,newContinent,newPopulation);
}


void listAllCountry(UI* ui){
    Repo* repo=getRepo(ui->ctrl);
	int length = getRepoLength(repo);
	if (length == 0){
        printf("There are no country with that string.");
	}
    for (int i = 0; i < getRepoLength(repo); i++){
        char str[200];
        toString(getCountryOnPos(repo, i), str);
        printf("%s\n", str);
    }
}

void listCountryString(UI* ui,char* what){
    // if(what=='\0'){
    //     listAllCountry(ui);
    // }
	Repo* repo = getRepoString(ui->ctrl,what);
	int length = getRepoLength(repo);
	if (length == 0){
        printf("There are no country with that string.");
	}
    else{
    	for (int i = 0; i < getRepoLength(repo); i++){
    		char str[200];
    		toString(getCountryOnPos(repo, i), str);
    		printf("%s\n", str);
    	}
    }
}

void startUI(UI* ui){
	while (1){
		printMenu();
		int cmd = getCmd();
		while (cmd == -1){
			printf("Please input a valid command!\n");
			cmd = getCmd();
		}
		if (cmd == 0)
			break;
		switch (cmd){
    		case 1:
    		{
    			int res = addCountryUI(ui);
    			if (res == 1)
    				printf("Country successfully added.\n");
    			else
    				printf("Error! Countryt could not be added, as there is another country with the same name or invalid continent!\n");
    			break;
    		}
    		case 2:
    		{
                int res = deleteCountryUI(ui);
    			if (res == 1)
    				printf("Country successfully deleted.\n");
    			else
    				printf("Error! Country could not be deleted, there isn't a country with the name!\n");
    			break;
    		}
    		case 3:
    		{
    			int res = updateCountryUI(ui);
    			if (res == 1)
    				printf("Update was successful.\n");
    			else
    				printf("No update could be made.\n");
    			break;
    		}
            case 4:
            {
                char name[50];
                readString("Please input the string to find: ",name);
                listCountryString(ui,name);
				break;
            }
            case 5:
            {
                listAllCountry(ui);
				break;
            }
		}
	}
}
