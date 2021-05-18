#include <platform.h>
#include <gpio.h>
#include "button.h"


int count = 0;

void button_press_isr(int sources) {

if ((sources << GET_PIN_INDEX(P_SW)) & (1 << GET_PIN_INDEX(P_SW))) {
 count++;
 
}

}