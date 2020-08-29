
/* Tested Button.c code from Arduino examples */

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  d13.pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  d2.pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = d2.digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    d13.digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    d13.digitalWrite(ledPin, LOW);
  }
}
