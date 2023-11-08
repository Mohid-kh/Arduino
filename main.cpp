#include <Arduino.h>

uint8_t buttonPin = 2;   // Push Button pin
int ledPin = 12;         // LED pin
bool ledOn = true;       // Track the state of the LED

int buttonState;

void ButtonRead();

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // PB as Input (Pulled up)
  pinMode(ledPin, OUTPUT);          // Initialize the LED as an output
}

void ButtonRead(void){

      digitalWrite(ledPin, LOW);  // Turn LED OFF when button pressed second time
      ledOn = false;
      delay(500);

}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if(buttonState == LOW)
  {
    ledOn = true;
  }

  while(buttonState == LOW && ledOn == true)
  {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    attachInterrupt(digitalPinToInterrupt(buttonPin), ButtonRead, FALLING); 
    // check if button is pressed again 
  }
  
}
