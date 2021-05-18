#include <platform.h>
#include <gpio.h>
#include "led.h"

void led_init(void){
	
	gpio_set_mode(P_LED,Output);
	
	led_set(0);
}

void led_set(int led_on){
	
	gpio_set(P_LED,led_on);
}