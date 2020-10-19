/*	Arduino Workshops 
* 	Starter Workshop 
*	Ws 1e Button Challenge
*   P.S. : All Bless Omotimos
*/

// Global Variable Declarations
bool Led1_On; 
int Led1 	= 9; 
int Led2 	= 13;  
int Button 	= 2; 
unsigned long currentMillis, previousMillis;
long interval;
int buttonState;

// Initializations go here
void setup() {
	Led1_On 	= true;				// Current player is Player 1 so LED 1 is On


	pinMode(Led1, OUTPUT); 			// LED 1 is output
	pinMode(Led2, OUTPUT);			// LED 2 is output
	pinMode(Button, INPUT);			// Button is Input

	digitalWrite(Led1, HIGH);		// Turn on LED 1 as per instructions
	digitalWrite(Led2, LOW);

	interval = 5000;
}

// Main Code goes here 
void loop() {
	buttonState = digitalRead(Button);
	currentMillis = millis(); 
	if (buttonState == HIGH || (currentMillis - previousMillis) >= interval ){
		previousMillis = currentMillis;
		if(Led1_On == true) {
			digitalWrite(Led1, LOW);
			digitalWrite(Led2, HIGH);  
		} else {
			digitalWrite(Led1, HIGH);
			digitalWrite(Led2, LOW); 
		}
		Led1_On = !Led1_On; 					// "!" means NOT, it forces true -> false and vice verca
		delay(100); 							// for button debouncing reasons, and let's be realistic you can't make a move in less than 100 ms :P
		// Interesting fact ! Since millis uses a timer to get the time value, 
		// the time measurement isnt't affected by the delay function

	}
}