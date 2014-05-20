// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
// #include <unisted.h> //Unix Supported Time fxn

typedef struct Interrupt{ char* interrupt_desc;
						  int id;
};

struct Interrupt IVR[5];
int rand_interrupt = 1;
int rand_interrupt_amount = 1;
double sleep = 5000;

void setupInterruptVectorTable(){
	struct Interrupt int1 = { "Power Event has occurred.", 0 };
	struct Interrupt int2 = { "I/O Event has occurred.", 1 };
	struct Interrupt int3 = { "Critical Event has occurred", 2 };
	struct Interrupt int4 = { "Exit Event has occurred", 3 };
	struct Interrupt int5 = { "Generic Event has occurred", 4 };
	IVR[0] = int1;
	IVR[1] = int2;
	IVR[2] = int3;
	IVR[3] = int4;
	IVR[4] = int5;
}

void vector_table_interrupt(){
	while (rand_interrupt != 9){
		if (rand_interrupt <= 4){
			printf("%s \n", IVR[rand_interrupt].interrupt_desc);
			printf("Interrupt successfully processed, CPU resuming processing \n ");
			Sleep(200);	//Used to slow down processing, so interrupts appear to occur in realtime
		}
		rand_interrupt = rand() % 10;
	}
}

void polling_interrupt(){
	printf("This will simulate 3 polling cycles \n");

	for (int i = 0; i < 3; i++){
		printf("Checking if an interrupt has occurred...");
		rand_interrupt_amount = rand() % 5;
		printf("%i interrupt(s) found!", rand_interrupt_amount);

		if (rand_interrupt <= 4 && rand_interrupt_amount > 0){
			for (int i = 0; i < rand_interrupt_amount; i++){
				rand_interrupt = rand() % 4;
				printf("%s \n", IVR[rand_interrupt].interrupt_desc);
				printf("Interrupt successfully processed, CPU resuming processing \n ");
			}
		}
		printf("Sleeping for %f ms \n", sleep);
		Sleep((DWORD) sleep);
	}
}

int main()
{
	int selection = -1;
	time_t t;
	time(&t);
	srand((unsigned int) t);
	setupInterruptVectorTable();

	while (selection != 1 && selection != 0){
		printf("Please press 0 to simulate Vector table interrupts, or 1 to simulate polling \n");
		scanf_s("%d", &selection);

		if (selection > 1 || selection < 0)
			printf("Invalid input \n");
	}
	
	if (selection == 0){
		vector_table_interrupt();
	}	
	else if (selection == 1){
			polling_interrupt();
		}
	return 0;
}


