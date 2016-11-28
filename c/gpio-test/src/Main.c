/*
 * Main.c
 *
 *  Created on: 26.11.2016
 *      Author: nils
 */

#include <stdio.h>
#include <time.h>

#include <wiringPi.h>

#include "Main.h"

int main(int argc, char **argv) {
	printf("Setting up wiringPi\n");
	//setup wiring pi
	wiringPiSetup();
	//Set pin 0 as out
	pinMode(RELAIS, OUTPUT);
	pinMode(LED_ON, OUTPUT);
	pinMode(LED_OFF, OUTPUT);
	turn_off();
	for(int i=0;i<10;i++){
		sleep(2);
		printf("switching ");
		if(get_status()==LOW){
			turn_on();
			printf("on\n");
		}else{
			turn_off();
			printf("off\n");
		}
	}
	all_off();
}
void turn_on(){
	digitalWrite(RELAIS, HIGH);
	digitalWrite(LED_ON, HIGH);
	digitalWrite(LED_OFF, LOW);
}
void turn_off(){
	digitalWrite(RELAIS, LOW);
		digitalWrite(LED_ON, LOW);
		digitalWrite(LED_OFF, HIGH);
}
void all_off(){
	digitalWrite(RELAIS, LOW);
		digitalWrite(LED_ON, LOW);
		digitalWrite(LED_OFF, LOW);
}
int get_status(){
	return digitalRead(RELAIS);
}
