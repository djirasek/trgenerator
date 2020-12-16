//============================================================================
// Name        : ReincarnGen.c
// Author      : Daniel Jirasek
// Version     : 0.05
// Description : Generates a new incarnation for a Tabletop RPG character,
//		 based on Pathfinder's official Reincarnation table
//============================================================================
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
//enum used to specify the fantasy races that do not fall within a range
enum incarn{OTHER = 0, BBEAR = 1, GNOLL = 26, LFOLK = 94,  TDYTE = 99, CHOICE = 100};
//takes the enum incarn to determine incarnation for races that have a range
void detPfIncarnation(void);
void detPfOther(unsigned int rval);
void det5eIncarnation(void);
unsigned int rollDice(void);

int main()
{
	unsigned int rval;
	int choice;
	printf("--------------Welcome to the Tabletop RPG Generator----------------------------------\n");
	printf("\tEnter 1 to roll according to Pathfinder's Official Reincarnation table\n");
	printf("\tEnter 2 to roll according to D&D 5E Reincarnation table\n");
	printf("\tEnter 9 to quit\n");
	printf("-------------------------------------------------------------------------------------\n\n");
	scanf("%d", &choice);
	while(choice != 9) {
		switch(choice){
			case 1:
				detPfIncarnation();
				break;
			case 2:
				printf("You chose the D&D 5E reincarnation table\n");
				break;
			default:
				printf("Error: Invalid choice made\n");
		}
		printf("--------------Welcome to the Tabletop RPG Generator----------------------------------\n");
		printf("\tEnter 1 to roll according to Pathfinder's Official Reincarnation table\n");
		printf("\tEnter 2 to roll according to D&D 5E Reincarnation table\n");
		printf("\tEnter 9 to quit\n");
		printf("-------------------------------------------------------------------------------------\n\n");
		scanf("%d", &choice);
	}
	
	return 0;
}

//function simulates the rolling of a die
unsigned int rollDice(void){
	unsigned int val;
	//used to ensure good random num gen
	struct timespec t;
	if(timespec_get(&t, TIME_UTC) == 0){
		perror("Error when calling timespec_get()");
	}
	//necessary in order for rand() to be called
	srandom(time(NULL));
	return (random() % 100) + 1;
}
//function for getting the appropriate name of incarnation associated with the value
void detPfIncarnation(void){
	unsigned int val;
	val = rollDice();
	switch(val)
	{
		//BugBear
		case BBEAR:
			printf("%d Bugbear\n", val);
			break;
		//Gnoll
		case GNOLL:
			printf("%d Gnoll\n", val);
			break;
		//Lizardfolk
		case LFOLK:
			printf("%d Lizardfolk\n", val);
			break;
		//Troglodyte
		case TDYTE:
			printf("%d Troglodyte\n", val);
			break;
		//Game Master's Choice for incarnation
		case CHOICE:
			printf("%d GM's Choice\n", val);
			break;
		//Default case handles characters that fall within ranges of numbers
		default:
			detPfOther(val);
			
	}
}
//Handles the other cases in the official PF reincarnation table
void detPfOther(unsigned int rval){
	//Dwarf
	if((rval>=2)&&(rval<=13)){
		printf("%d Elf\n", rval);
	}
	//Elf
	if((rval>=14)&&(rval<=25)){
		printf("%d Elf\n", rval);
	}
	//GNOME
	else if((rval>=27)&&(rval<=38)){
		printf("%d GNOME\n", rval);
	}
	//Goblin
	else if((rval>=39)&&(rval<=42)){
		printf("%d Goblin\n", rval);
	}
	//Half-Elf
	else if((rval>=43)&&(rval<=52)){
		printf("%d Half-Elf\n", rval);
	}
	//Half-Orc
	else if((rval>=53)&&(rval<=62)){
		printf("%d Half-Orc\n", rval);
	}
	//Halfling
	else if((rval>=63)&&(rval<=74)){
		printf("%d Halfling\n", rval);
	}
	//Human
	else if((rval>=75)&&(rval<=89)){
		printf("%d Human\n", rval);
	}
	//KOBOLD
	else if((rval>=90)&&(rval<=93)){
		printf("%d Kobold\n", rval);
	}
	//Orc
	else if((rval>=95)&&(rval<=98)){
		printf("%d Orc\n", rval);
	}
	//else case
	else {

	}
}
//handles incarnations based off 5E reincarnation table
void det5EIncarnation(){
	unsigned int val;
	val = rollDice();
	printf("Incarnation value: %d", val);

}
