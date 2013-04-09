/*
   	The next code allows you to configure the bluetooth HC-06 module directly through Arduino.
	You can adjust the name, the code and the baud rate of the module.
	The Bluetooth settings are saved in the module so you just need to configure it once.arlo una vez.
    
	After uploading the code to Arduino it has 10 secongs to connect the module, when the LED turns off
	and the configuration process will start. Finished the configuration process, the LED will start blinking.

	** Configuration must be done with the module in a non-paired state **
*/
 
 
// Configuration Settings:
    char ssid[10]        = "Linvor05";    // BT module name
    char baudios         = '4';           // 1=>1200 baudios, 2=>2400, 3=>4800, 4=>9600 (default), 5=>19200, 6=>38400, 7=>57600, 8=>115200
    char password[10]    = "0000";        // Pairing password for the BT module
 
 
void setup()
{
    Serial.begin(9600); //Change 9600 for the set value if not default
    
    // Waiting time:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(10000);
        digitalWrite(13,LOW);
    
    // Module configuration:
    
        // Starts configuration:
            Serial.print("AT"); delay(1000);
 
        // Adjusting bluetooth name:
            Serial.print("AT+NAME"); Serial.print(ssid); delay(1000);
 
        // Baud rate adjust:
            Serial.print("AT+BAUD"); Serial.print(baudios); delay(1000);
 
        // Password adjust:
            Serial.print("AT+PIN"); Serial.print(password); delay(1000);    
}
 
void loop()
{
    // When the led begins to blink, you´re done:
    digitalWrite(13, !digitalRead(13));
    delay(500);
}
