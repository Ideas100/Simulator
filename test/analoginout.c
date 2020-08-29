
/* Tested the modified version of AnalogInOutSerial.c code in Arduino example */

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
	// initialize serial communications at 9600 bps:
	//Serial.begin(9600);
	a0.pinMode(A0, INPUT);
	d9.pinMode(9, OUTPUT);
}

void loop() {
	// read the analog in value:
	sensorValue = a0.analogRead(analogInPin);
	// map it to the range of the analog out:
	// outputValue = map(sensorValue, 0, 1023, 0, 255);
	outputValue = (sensorValue * 255) / 1023;
        // change the analog out value:
	d9.analogWrite(analogOutPin, outputValue);

	// print the results to the Serial Monitor:
	//Serial.print("sensor = ");
	//Serial.print(sensorValue);
	//Serial.print("\t output = ");
	//Serial.println(outputValue);

	// wait 2 milliseconds before the next loop for the analog-to-digital
	// converter to settle after the last reading:
	delay(2);
}
