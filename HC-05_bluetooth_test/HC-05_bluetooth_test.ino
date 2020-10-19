#include <SoftwareSerial.h>
SoftwareSerial BTserial(8, 9); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
 
char c = ' ';
 
void setup() 
{
    // start th serial communication with the host computer
    Serial.begin(9600);
    Serial.println("Arduino with HC-05 is ready");
 
    // start communication with the HC-05 using 38400
    BTserial.begin(9600);  
    Serial.println("BTserial started at 9600");
}
 
void loop()
{
 
     // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available()){  
        c = BTserial.read();
        Serial.write(c);
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available()){
        c =  Serial.read();
 
        // mirror the commands back to the serial monitor
        // makes it easy to follow the commands
        Serial.write(c);   
        BTserial.write(c);  
    }
 
}
