#include <gpio.h>
#include <view.h>

#include <unistd.h>
#include <cstdlib>
/*
 *  D_Gpio 14 objects refers to the 14 digital pins in Arduino uno
 *  A_Gpio 6 objects refers to the 6 analog pins in Arduino uno
 */
D_Gpio d0(0), d1(0), d2(0), d3(1), d4(0), d5(1), d6(1),
	d7(0), d8(0), d9(1), d10(1), d11(1), d12(0), d13(0);

A_Gpio a0(0), a1(0), a2(0), a3(0), a4(0), a5(0);

/* 
 *  The delay function with arguments as milliseconds
 */
void delay(int millis)
{
	usleep(millis * 1000);
}

void setup(void);
void loop(void);

string title_str = "Text based Arduino simulation";
string file_name = getenv("FILEPATH");

int main()
{
	View view;

	view.print_title(title_str, 0);
	view.print_title(file_name, 1);
	
	setup();
	while(1) 
		loop();
	
	view.cleanup();

	return 0;
}






