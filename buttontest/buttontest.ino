const int b1=5;
const int led=7;
boolean lastbutton=LOW;
boolean currentbutton=LOW;
boolean ledon=false;

void setup() {
//Serial.begin(9600);
pinMode(b1,INPUT);
pinMode(led,OUTPUT);
}


boolean debounce(boolean last) {
  boolean current=digitalRead(b1);
  if(last!=current) {
    delay(5);
    current=digitalRead(b1);
  }
  return current;
}

void loop() {

currentbutton=debounce(lastbutton);
if(lastbutton==LOW && currentbutton==HIGH) {
  ledon=!ledon;
}
  lastbutton=currentbutton;

  digitalWrite(led,ledon);

     
  }
  
 
