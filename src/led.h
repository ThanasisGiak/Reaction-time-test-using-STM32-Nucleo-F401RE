/*!
 * \file      leds.h
 * \brief     Controls an RGB LED.
 * \copyright ARM University Program &copy; ARM Ltd 2016.
 */
#ifndef LED_H
#define LED_H

/*! \brief Initializes the pins for the red, green, and blue LEDs.
 */
void led_init(void);

/*! \brief Sets the RGB LED to a certain colour.
 *  \param red_on    Turn on the red LED.
 *  \param green_on  Turn on the green LED.
 *  \param blue_on   Turn on the blue LED.
 */
void led_set(int led_on);

#endif // LED_H

// *******************************ARM University Program Copyright © ARM Ltd 2016*************************************   
