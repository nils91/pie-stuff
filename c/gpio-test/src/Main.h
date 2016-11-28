/*
 * Main.h
 *
 *  Created on: 28.11.2016
 *      Author: nils
 */

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#define RELAIS 0
#define LED_ON 24
#define LED_OFF 29

void turn_on(void);
void turn_off(void);
int get_status(void);

#endif /* SRC_MAIN_H_ */
