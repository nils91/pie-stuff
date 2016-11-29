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

unsigned long turn_on_time=0;
unsigned long turn_off_time=0;

int main(int argc, char **argv) {
	printf("Setting up wiringPi\n");
	//setup wiring pi
	wiringPiSetup();
	//Set pin 0 as out
	pinMode(RELAIS, OUTPUT);
	pinMode(LED_ON, OUTPUT);
	pinMode(LED_OFF, OUTPUT);
	pinMode(BUTTON_IN, INPUT);
	pullUpDnControl(BUTTON_IN,PUD_DOWN);
	wiringPiISR(BUTTON_IN,INT_EDGE_RISING,&ISR_btn_in);
	pinMode(BUTTON_OUT, INPUT);
		pullUpDnControl(BUTTON_OUT,PUD_DOWN);
		wiringPiISR(BUTTON_OUT,INT_EDGE_RISING,&ISR_btn_out);
		pinMode(BUTTON_CONF, INPUT);
			pullUpDnControl(BUTTON_CONF,PUD_DOWN);
			wiringPiISR(BUTTON_CONF,INT_EDGE_RISING,&ISR_btn_conf);
	turn_off();
	for(;;){
		if(get_status()==HIGH){
			if(time(0)-turn_on_time > 3){
				turn_off();
			}
		}
		delay(200);

	}
	all_off();
}
void turn_on(){
	turn_on_time=time(0);
	digitalWrite(RELAIS, HIGH);
	digitalWrite(LED_ON, HIGH);
	digitalWrite(LED_OFF, LOW);
}
void turn_off(){
	turn_off_time=time(0);
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

void ISR_btn_in(){
	turn_on();
}
void ISR_btn_out(){
	turn_on();
}
void ISR_btn_conf(){
	turn_off();
}
