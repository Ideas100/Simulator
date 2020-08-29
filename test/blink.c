
/* Tested the Blink code from Arduino examples. */

void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	d13.pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
	d13.digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
	delay(1000);                         // wait for a second
	d13.digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
	delay(1000);                         // wait for a second
}
