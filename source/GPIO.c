/*
 * GPIO.c
 *
 *  Created on: 21 abr 2022
 *      Author: ADNBOOT
 */
#include "GPIO.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
static uint8_t volatile Switch2Press = 0;
static uint8_t volatile Switch3Press = 0;

void PORTA_IRQHandler(void)
	{
	    GPIO_PortClearInterruptFlags(GPIOA, 1u << PIN04);

	    Switch3Press = 1;

	    SDK_ISR_EXIT_BARRIER;
	}
void PORTC_IRQHandler(void)
	{
	    GPIO_PortClearInterruptFlags(GPIOC, 1u << PIN06);

	    Switch2Press = 1;

	    SDK_ISR_EXIT_BARRIER;
	}

uint8_t GPIO_intr_getswitch3(void){
		return(Switch3Press);

	}
uint8_t GPIO_intr_getswitch2(void){
		return(Switch2Press);
}

void GPIO_intr_clear(uint8_t *a){
	if(a==3){
	 Switch3Press=0;
			}
	if(a==2){
	 Switch2Press=0;
			}
	}

void GPIO_init (void){

	/*----------------------------------------
		Configuración LEDs
	-------------------------------------------*/
	gpio_pin_config_t led_config1 = {
	        kGPIO_DigitalOutput,
	        1,
	    };
	gpio_pin_config_t led_config2 = {
	        kGPIO_DigitalOutput,
	        1,
	    };
	gpio_pin_config_t led_config3 = {
	        kGPIO_DigitalOutput,
	        1,
	    };
	/*----------------------------------------
		Configuración de push buttons
	---------------------------------------*/
	gpio_pin_config_t sw_config1 = {
	        kGPIO_DigitalInput,
	        0,
	    };
	gpio_pin_config_t sw_config2 = {
	        kGPIO_DigitalInput,
	        0,
	    };


	//--------------------------------------


	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortB);//SIM->SCGC5 = 0x400;
	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortE);
	//Leds
    PORT_SetPinMux(PORTB, PIN22, kPORT_MuxAsGpio); //PORTB->PCR[22] = 0x00000100;
	PORT_SetPinMux(PORTB, PIN21, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, PIN26, kPORT_MuxAsGpio);
	//Buttons
	PORT_SetPinMux(PORTC, PIN06, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, PIN04, kPORT_MuxAsGpio);

	//Inicializo Leds
	GPIO_PinInit(GPIOB, PIN22, &led_config1);//rojo
	GPIO_PinInit(GPIOB, PIN21, &led_config2);//Azul
	GPIO_PinInit(GPIOE, PIN26, &led_config3);	//verde
	//inicializo Push Button
	GPIO_PinInit(GPIOC, PIN06, &sw_config1);//up
	GPIO_PinInit(GPIOA, PIN04, &sw_config2);//down

	PORT_SetPinInterruptConfig(PORTA, PIN04, kPORT_InterruptFallingEdge);
	PORT_SetPinInterruptConfig(PORTC, PIN06, kPORT_InterruptFallingEdge);
	NVIC_EnableIRQ(PORTC_IRQn);
	NVIC_EnableIRQ(PORTA_IRQn);
	 	/**It Sets the priority of the IRQ*/
	NVIC_SetPriority(PORTC_IRQn, 2);
	NVIC_SetPriority(PORTA_IRQn, 2);

}
