#include <stdio.h>
#include "fsl_common.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_common.h"
#include "GPIO.h"
#include "LEDRGB.h"
//--------------------------------------

int main(void) {
    uint8_t BANDERA=5,status1=0;
    GPIO_init();
    while(1) {
   if(BANDERA<9){
	   status1=GPIO_intr_getswitch2();
    	if (status1)
				{
    			BANDERA++;
    			GPIO_intr_clear(SWITCH2);
    			}
   	   }

    if(BANDERA>0){
    	status1=GPIO_intr_getswitch3();
		if(status1){
					BANDERA--;
					GPIO_intr_clear(SWITCH3);
					}
    			}

	if(status1&(!GPIO_PinRead(GPIOC, PIN06))){
		BLANCORGB();
	    for(int i=0;i<1000010;i++);

			}

	else{
		//GPIO_PortSet(GPIOB, 1u << PIN22);
 		printf("nada");
		}

 switch(BANDERA){
 case 0: AMARILLORGB();
	 	 break;
 case 1: ROJORGB();
 	  	 break;
 case 2:MORADORGB();
	     break;
 case 3: AZULRGB();
	 	 break;
 case 4:VERDERGB();
	     break;
 case 6: AMARILLORGB();
	 	 break;
 case 7: ROJORGB();
	  	 break;
 case 8:MORADORGB();
	     break;
 case 9: AZULRGB();
	 	 break;
 case 10:
	 	VERDERGB();
	 	 break;
 default:
	 	APAGADORGB();
	     break;

 	 	 	 	 }


    }
    return 0 ;
}
