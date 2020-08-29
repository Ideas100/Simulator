/* Gpio.h - handles the all necessary gpio pin functionalities. */
#ifndef __GPIO_H__
#define __GPIO_H__

#include "view.h"

/* Predefined Macros for Arduino functions */
#define LED_BUILTIN 13
#define LOW    0
#define HIGH   1
#define INPUT  0
#define OUTPUT 1

/* Interger constant for Digital and Analog Pins
 *  - Digital Pins can be given either 0-13 or D0-D13
 *  - Analog Pins can be given only with A0-A5
 */
enum { D0, D1, D2, D3, D4, D5, D6,
       D7, D8, D9, D10, D11, D12, D13,
       A0, A1, A2, A3, A4, A5
};

/* Working with Input mode requires input from user
 * Hence these keyboard buttons were predefined for 
 * Analog and Digital inputs.
 */
static struct
{
	char ch;
} button_c[] = {'0', '1', '2', '3', '4', '5', '6',
		'7', '8', '9', '+', '-', '*', '/',
		'q', 'w', 'e', 'r', 't', 'y',
		'a', 's', 'd', 'f', 'g', 'h'
};

/* class Gpio
 *  - stores general info about the gpio pins i.e, pin_no, 
 *    mode & value.
 *  - parent class for D_Gpio and A_Gpio class.
 */
class Gpio : public View
{
public:
	int pin_id;
	int mode;
	int value;
	
	void pinMode(int pin_no, int set_mode);
};

/* class D_Gpio
 *  - Inherits the property of base class Gpio.
 *  - Digital pins property and functions are handled.
 *  - PWM pins are (3, 5, 9, 10, 11) that are given
 *    predefined construtor input while declaring objects
 *    in the main.cpp
 */
class D_Gpio : public Gpio
{
	
public:
	int pwm_pin;
	D_Gpio(int set) {
		pwm_pin = set;
	}
	int digitalRead(int pin_no);
	void digitalWrite(int pin_no, int set_value);
	void analogWrite(int pin_no, int set_value);
};

/* class A_Gpio
 *  - Inherits the property of base class Gpio, D_Gpio.
 *  - Analog pins property and function are handled.
 */
class A_Gpio : public D_Gpio
{ 
public:
	A_Gpio(int set):D_Gpio(set){
		D_Gpio::pwm_pin = set;
	}
	int analogRead(int pin_no);
};
	
#endif  /* __GPIO_H__ */
