#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;
	return ui;
}

void destroyUI(UI * ui)
{
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
void printMenu()
{
    int i=0;
    printf("\n");
    for(i=0;i<30;++i)
    printf("*");
    printf("\n");
	printf("1 - Add a country.\n");
	printf("2 - Delete a country.\n");
	printf("3 - Update a country.\n");
	printf("4 - List countrys with a given string.\n");
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
int getInteger(const char *message) {
    char s[100];
    int ret = 0;
    printf("%s", message);
    scanf("%s", s);
    while(sscanf(s, "%d", &ret) != 1) {
        printf("%s",message);
        scanf("%s", s);
    }
    return ret;
}

int getCmd() {
    int cmd = getInteger("Give command: ");
    if (cmd >=1 || cmd <=4)
        return cmd;
    return -1;
}

// void readStringWithSpaces(const char* message, int maxStrSize, char str[])
// {
// 	printf("%s\n",message);
// 	fgets(str, maxStrSize, stdin);
// 	// the newline is also read so we must eliminate it from the string
// 	int size = strlen(str) - 1;
// 	if (str[size] == '\n')
// 		str[size] = '\0';
// }
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
int addCountrytUI(UI* ui)
{
	// read the planet's data
	char name[50], continent[50];
	int population;
	readString("Please input the name: ", name);
    readString("Please input the continent: ",continent);
	printf("Please input the population: ");
	scanf("%d", &population);

	return addCountryCtrl(ui->ctrl, name, continent, population);
}


void listAllCountryts(UI* ui)
{
	Repo* repo = getRepo(ui->ctrl);
	int length = getRepoLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored planets.";
		printf("%s \n", str);
	}

	for (int i = 0; i < getRepoLength(repo); i++)
	{
		char str[200];
		toString(getCountryOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int cmd = getCmd();
		while (cmd == -1)
		{
			printf("Please input a valid command!\n");
			cmd = getCmd();
		}
		if (cmd == 0)
			break;
		switch (cmd)
		{
		case 1:
		{
			int res = addCountrytUI(ui);
			if (res == 1)
				printf("Country successfully added.\n");
			else
				printf("Error! Countryt could not be added, as there is another country with the same name or invalid continent!\n");
			break;
		}
		case 2:
		{
            // int res = deleteCountryUI(ui);
			// if (res == 1)
			// 	printf("Country successfully deleted.\n");
			// else
			// 	printf("Error! Country could not be deleted, there isn't a country with the name!\n");
			break;
		}
		case 3:
		{
			// int res = updateCountryUI(ui->ctrl);
			// if (res == 1)
			// 	printf("Update was successful.\n");
			// else
			// 	printf("No update could be made.\n");
			break;
		}
        case 4:{
            listAllCountryts(ui);
        }
		}
	}
}
