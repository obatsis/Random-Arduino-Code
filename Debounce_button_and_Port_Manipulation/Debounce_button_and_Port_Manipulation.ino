/*
B (digital pin 8 to 13)
C (analog input pins)
D (digital pins 0 to 7)

PORTD maps to Arduino digital pins 0 to 7

DDRD - The Port D Data Direction Register - read/write
PORTD - The Port D Data Register - read/write
PIND - The Port D Input Pins Register - read only

PORTB maps to Arduino digital pins 8 to 13 The two high bits (6 & 7) map to the crystal pins and are not usable

DDRB - The Port B Data Direction Register - read/write
PORTB - The Port B Data Register - read/write
PINB - The Port B Input Pins Register - read only

PORTC maps to Arduino analog pins 0 to 5. Pins 6 & 7 are only accessible on the Arduino Mini

DDRC - The Port C Data Direction Register - read/write
PORTC - The Port C Data Register - read/write
PINC - The Port C Input Pins Register - read only


DDRD = DDRD |  B01100100;   //1->output, 0->input  TO OR einai gia na apofigo tin allagi ton 0, 1 pou einai tx, rx
PORTD = B00011000;   //for pullup(sets these bit HIGH)

if (PINB & 0b00000001)    something;                  // if(digitalRead(8)==HIGH)   something;
else                      something else;                  // if (digitalRead(8)==LOW)   something else;

*/
int readflag=1;
long current, previous, interval;
void setup() {

  DDRH = DDRH | B00000000;// pinMode(button, INPUT_PULLUP);
  PORTH = B00100000;//pullup
  DDRE=B00001000;
  interval=300;       //miliseconds
//  
}

void loop() {
  current=millis();
  if(!(PINH & 0b0100000) && readflag==1) { //if(digitalRead(button)==LOW)  maybe wrong
   PORTE |=(1<<3);
   delay(50);
   PORTE &= ~(1<<3);
    //code
    readflag=0;
    current=millis();
    previous=current;
    previous +=interval;
  }
  if(current>previous){   //better
   if(PINH & 0b00100000){  
       readflag=1;
    }
  }
  delay(10);
}
