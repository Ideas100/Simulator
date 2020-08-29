#include <gpio.h>

/* starting postion of the pins */
static int position = 3;

/* List of error message's */
static struct
{
	string str; 
} err_msg[] = {
	"The pin is declared as output",
	"The pin is declared as input",
	"The pin doesn't match or declared",
	"The given pin is not PWM pin",
	"The analogWrite value should be between 0-255"
};

void Gpio::pinMode(int pin_no, int set_mode)
{
	/* Keeping track of pin position's */
	position += 2;
	View::cur_pos = position; 
	
        pin_id = pin_no;
        mode = set_mode;
        value = 0;
	
	View::print(pin_no, mode, value, 0);	
}

void D_Gpio::digitalWrite(int pin_no, int set_value)
{
	if (Gpio::pin_id == pin_no && Gpio::mode == OUTPUT) {
		
		Gpio::value = set_value;
		View::print(pin_no, mode, value, 1);
		
	} else if (Gpio::mode != OUTPUT) {
		View::print_err(pin_no, err_msg[1].str);
	} else {
		View::print_err(pin_no, err_msg[2].str);
	}
}


int D_Gpio::digitalRead(int pin_no)
{
	if (Gpio::pin_id == pin_no && Gpio::mode == INPUT) {
		
		/* Giving a hint about which button is defined */
		View::D_button_view(button_c[pin_id].ch);

		if (View::read_() == button_c[pin_id].ch) {
			value = 1;
		} else {
		        value = 0;	
		}
		View::print(pin_no, mode, value, 1);
		return Gpio::value;
		
	} else if (Gpio::mode != INPUT) {
		View::print_err(pin_no, err_msg[0].str);
	} else {
		View::print_err(pin_no, err_msg[2].str);
	}
	
	return 0;
}

void D_Gpio::analogWrite(int pin_no, int set_value)
{
	if (D_Gpio::pwm_pin == 1) {
		
		if (Gpio::pin_id == pin_no && Gpio::mode == OUTPUT) {
			
			if (set_value >=0 && set_value <= 255) {
				Gpio::value = set_value;
				View::print(pin_no, mode, value, 0);
			} else {
				View::print_err(pin_no, err_msg[4].str);
			}
			
		} else if (Gpio::mode != OUTPUT) {
			View::print_err(pin_no, err_msg[1].str);
		} else {
			View::print_err(pin_no, err_msg[2].str);
		}
		
	} else {
		View::print_err(pin_no, err_msg[3].str);
	}
}

int A_Gpio::analogRead(int pin_no)
{
	char ch;
	if (Gpio::pin_id == pin_no && Gpio::mode == INPUT) {

		View::A_button_view(button_c[pin_id].ch, button_c[pin_id+6].ch);

		ch = read_();
		if (ch == button_c[pin_id].ch)
			value += 4;
		if (ch == button_c[pin_id+6].ch)
			value -= 4;
		if (value > 1023)
			value = 0;
		if (value < 0 )
			value = 1023;
		View::print(pin_no, mode, value,0);
		
	} else if (Gpio::mode != INPUT) {
		View::print_err(pin_no, err_msg[0].str);
	} else {
		View::print_err(pin_no, err_msg[2].str);
	}
	
	return Gpio::value;
}
