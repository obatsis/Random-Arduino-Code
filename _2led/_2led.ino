int led2=2;
int led3=3;
int pot=0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

}



void loop() {
/*  digitalWrite(LED_BUILTIN, HIGH);   
  delay(10);                       
  digitalWrite(LED_BUILTIN, LOW);  
  delay(1000);    */                       
 
  int  dl=analogRead(pot);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,LOW);
   delay(dl);

   digitalWrite(led3,HIGH);
   digitalWrite(led2,LOW);
   delay(dl);



}
