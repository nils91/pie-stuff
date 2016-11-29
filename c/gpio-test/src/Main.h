/*
 * Main.h
 *
 *  Created on: 28.11.2016
 *      Author: nils
 */

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#define RELAIS 0
#define LED_ON 29
#define LED_OFF 24
#define BUTTON_IN 1
#define BUTTON_OUT 2
#define BUTTON_CONF 3

void turn_on(void);
void turn_off(void);
void all_off(void);
int get_status(void);
void ISR_btn_in(void);
void ISR_btn_out(void);
void ISR_btn_conf(void);

#endif /* SRC_MAIN_H_ */
