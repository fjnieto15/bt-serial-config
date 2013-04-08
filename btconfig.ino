#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3

SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
	
	Serial.begin(9600);
	bluetooth.begin(9600);

  	Serial.println("Serial active...");

}/*end setup*/

void loop() {

  	if (bluetooth.available()) {  
    	Serial.write(bluetooth.read());
	}/*end if*/

  	if (Serial.available()) {
    	bluetooth.write(Serial.read());
  	}/*end if*/

}/*end loop*/
