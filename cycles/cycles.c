#include <platform.h>
#include <gpio.h>
#include "cycles.h"
#include <stdio.h>

volatile unsigned int *DWT_CYCCNT  ;
volatile unsigned int *DWT_CONTROL ;
volatile unsigned int *SCB_DEMCR   ;

void reset_cycles_counter(){
    DWT_CYCCNT   = (int *)0xE0001004; //address of the register
    DWT_CONTROL  = (int *)0xE0001000; //address of the register
    SCB_DEMCR    = (int *)0xE000EDFC; //address of the register
    *SCB_DEMCR   = *SCB_DEMCR | 0x01000000;
    *DWT_CYCCNT  = 0; // reset the counter
    *DWT_CONTROL = 0; 
}

void start_cycles_counter(){
    *DWT_CONTROL = *DWT_CONTROL | 1 ; // enable the counter
}

void stop_cycles_counter(){
    *DWT_CONTROL = *DWT_CONTROL | 0 ; // disable the counter    
}

unsigned int getCycles(){
    return *DWT_CYCCNT;
}
