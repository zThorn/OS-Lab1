// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
// #include <unisted.h> //Unix Supported Time fxn

int main()
{
	int rand_interrupt = 1;
	int selection = 1;
	double sleep = 5000;
	time_t t;
	time(&t);


	srand((unsigned int)t);
	if (selection == 0){
		while (rand_interrupt != 0){
			switch (rand_interrupt){
			case 0:
				printf("System");
				break;

			case 1:

				printf("Interrupt successfully processed, CPU resuming processing ");
				break;

			case 2:

				break;
			case 3:
				
				break;
			case 4:

				break;
			case 5:

				break;
			default:
				printf("Stan");



			}
			rand_interrupt = rand() % 10;
		}
	}

	else if (selection == 1){
		printf("Checking for interrutps....");

		switch (rand_interrupt){





		}
		rand_interrupt = rand() % 10;
		printf("Sleeping for %f ms", sleep);
		Sleep((DWORD) sleep);


	}

	return 0;
}
