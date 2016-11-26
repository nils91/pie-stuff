/*
 * Main.c
 *
 *  Created on: 26.11.2016
 *      Author: nils
 */

#include <stdio.h>
#include <time.h>

#include <wiringPi.h>

int main(int argc, char **argv) {
	printf("Setting up wiringPi\n");
	//setup wiring pi
	wiringPiSetup();
	//Set pin 0 as out
	pinMode(0, OUTPUT);
	while(1){
		digitalWrite(0,!digitalRead(0)); //invert pin 0
		sleep(2);
	}
}
