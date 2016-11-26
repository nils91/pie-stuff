/*
 * Main.c
 *
 *  Created on: 26.11.2016
 *      Author: nils
 */

#include <stdio.h>

#include <wiringPi.h>

int main(int argc, char **argv) {
	printf("Setting up wiringPi\n");
	//setup wiring pi
	wiringPiSetup();
}
