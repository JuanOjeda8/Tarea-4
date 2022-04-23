/*
 * LEDRGB.c
 *
 *  Created on: 21 abr 2022
 *      Author: ADNBOOT
 */
#include "LEDRGB.h"
#include "GPIO.h"
#include "fsl_common.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_common.h"
void AZULRGB(void){
	GPIO_PortClear(GPIOB, 1u << PIN21);//azul
	GPIO_PortSet(GPIOB, 1u << PIN22);
	GPIO_PortSet(GPIOE, 1u << PIN26);
}
void VERDERGB (void){
	 GPIO_PortClear(GPIOE, 1u << PIN26);
	 GPIO_PortSet(GPIOB, 1u << PIN21);
}
void ROJORGB (void){
	 GPIO_PortClear(GPIOB, 1u << PIN22);//rojo
	 GPIO_PortSet(GPIOE, 1u << PIN26);
	 GPIO_PortSet(GPIOB, 1u << PIN21);
}
void AMARILLORGB (void){
	GPIO_PortClear(GPIOB, 1u << PIN22);//amarillo ro+ve
	GPIO_PortClear(GPIOE, 1u << PIN26);
}
void MORADORGB (void){
	GPIO_PortClear(GPIOB, 1u << PIN22);//morado ro+azul
	GPIO_PortClear(GPIOB, 1u << PIN21);
}
void APAGADORGB(){
	 GPIO_PortSet(GPIOB, 1u << PIN21);
	 GPIO_PortSet(GPIOB, 1u << PIN22);
	 GPIO_PortSet(GPIOE, 1u << PIN26);
}
void BLANCORGB(void){
	GPIO_PortClear(GPIOB, 1u << PIN21);
	GPIO_PortClear(GPIOB, 1u << PIN22);
	GPIO_PortClear(GPIOE, 1u << PIN26);
}
