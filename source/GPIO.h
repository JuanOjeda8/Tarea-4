/*
 * GPIO.h
 *
 *  Created on: 21 abr 2022
 *      Author: ADNBOOT
 */

#ifndef GPIO_H_
#define GPIO_H_
#include <stdint.h>

#define PIN21        21u
#define PIN22        22u
#define PIN26        26u

#define PIN06        6u
#define PIN04        4u
#define SWITCH3      3u
#define SWITCH2      2u

void GPIO_init(void);
uint8_t GPIO_intr_getswitch3(void);
uint8_t GPIO_intr_getswitch2(void);
void GPIO_intr_clear(uint8_t *a);


#endif /* GPIO_H_ */
