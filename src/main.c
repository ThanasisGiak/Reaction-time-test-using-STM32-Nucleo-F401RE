#include <platform.h>
#include <stdio.h>
#include <stdlib.h>
#include <gpio.h>
#include "button.h"
#include "led.h"
#include <delay.h>
#include <time.h>
#include <cycles.h>
#include <stdint.h>
#define EX 'Led_on'         // define what kind of expirement to have,there are two options Led_on and Led_off
#define EXP_NUM 5        // define the number of time that the expirement takes place


int main(void) {
	uint32_t cycles=0;      // number of cycles 
	static double a;       // variable a is used to generate random delays
  static int b,prev_count,exp; /*variable b is used to generate random delays,prev_count is used to store number of times button pressed,
	,exp to store the number of expirements that have took place */
	float cycle_time=(float)1/(float)SystemCoreClock;   // cycle_time stores the time of  a core cycle,our core clock frequency is 16Mhz 
	static float median_time;                          // stores the median value of time for every expirement
// Initialise LEDs.
  led_init();
  led_set(0);                                       // switch led off

// Set up on-board switch.
  gpio_set_mode(P_SW, PullUp);                     // pullup mode
  gpio_set_trigger(P_SW, Rising);                 // interupt triggered on rising edge of the clock
  gpio_set_callback(P_SW, button_press_isr);     // button_press_isr is called when someone push the button
  __enable_irq();                               // enable interupts
	
 	 switch (EX){
		case 'Led_on' :                            // led on expirement
        while (exp<EXP_NUM) {
	            
	            reset_cycles_counter();         // reset timer
              
	  
	            
	            a= rand();                        // store a random number 
		          b= ((int)(a/100000000)-10)*1000; // change the value of variable a to be from 1000 to 10000
		          if (b>10000){
			            b=10000;
		          }
			        else if (b<= 0){
				              b=1000;
				
			        }
	           delay_ms(b);                      // delay from 1 to 9 ms
             prev_count=count;			          // store count(times that button have been pressed)
	           led_set(1);						         // switch on led
							
             start_cycles_counter();        // start counting cycles
	          
	      while (count == prev_count){       // loop until the button is pressed
		    }
				     
				     stop_cycles_counter();       // stop counting cycles
	           cycles += getCycles();      // get cycle counter 
              
	           led_set(0);                // switch off led
             exp++;                      
  

        }
        median_time=(cycles*cycle_time)/exp; // calculate median time of reaction


        break;

		case 'Led_off' :                        // led off experiment
			  while (exp<EXP_NUM) {
	            led_set(1);                  // switch on led
	             reset_cycles_counter();    // reset cycles counter
	            
	            a= rand();                         // store a random number
		          b= ((int)(a/100000000)-10)*1000;  // change the value of variable a to be from 1000 to 10000
		          if (b>10000){
			            b=10000;
		          }
			        else if (b<= 0){
				      b=1000;
				      }
	            delay_ms(b);                      // delay from 1 to 9 ms
              prev_count=count;			           // store count(times that button have been pressed)
	            led_set(0);                     // switch off led
	            start_cycles_counter();        // start counting cycles
	      while (count == prev_count){
		    }
				       stop_cycles_counter();        // stop counting cycles
	            cycles += getCycles();        // get cycle counter 
               
	            led_set(1);                  // switch on led
              exp++;
  

        }
        median_time=(cycles*cycle_time)/exp;   //calculate median time of reaction


        break;
   }
}
