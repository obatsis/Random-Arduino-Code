#include <SoftwareSerial.h>
SoftwareSerial s7s(9,10); //RX,TX 

const int buttonscrollf=3;
const int buttonscrollb=2;  
const int buttonselectsemi=4;
const int buttonselectfull=5;
const int displaybutton=6;
                          
int rx=0;
int spot[20];
char inSerial[15];

int j=22;
int cnt=0;
int state[20];


char tempString[10];
char brightString[10]; 
byte bright_idx=4;
const uint8_t  bright[5]={0,25,50,75,100};


void setup(){
  Serial.begin(9600);
  //BTserial.begin(38400);
  s7s.begin(9600);
  s7s.write(0x7A);
  s7s.write((byte) 100);
  sprintf(brightString,"b%03d",100);
  s7s.print(brightString);
  sprintf(tempString,"%4d",cnt+1);
  s7s.print(tempString);
  s7s.write(0x76);  
  
  pinMode(buttonscrollf,INPUT_PULLUP);
  pinMode(buttonscrollb,INPUT_PULLUP);
  pinMode(buttonselectsemi,INPUT_PULLUP);
  pinMode(buttonselectfull,INPUT_PULLUP);
  pinMode(displaybutton,INPUT_PULLUP);
  pinMode(rx,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  
  for(int i=0; i<20; i++){  
    spot[i]=j;
    pinMode(spot[i],OUTPUT);
    state[i]=0;
    j++;
  }
}

void brightChange(){
  bright_idx++;
  bright_idx=bright_idx%5;
  s7s.write(0x7A);
  s7s.write((byte) bright[bright_idx]);
  sprintf(brightString,"b%03d",bright[bright_idx]);
  s7s.print(brightString);
  digitalWrite(displaybutton,HIGH);
  delay(500);
  s7s.print(tempString);
  if(state[cnt]==1){
    blinkstate();
  }
}

void scrollf(){
  cnt++;
  if(cnt==20){  
    cnt=0;   
  }
  sprintf(tempString,"%4d",cnt+1);
  s7s.print(tempString);
  if(state[cnt]==1){
    blinkstate();
  }
  delay(600); 
}

void scrollb(){
  cnt--;
  if(cnt==-1){
    cnt=19;
  }
  sprintf(tempString,"%4d",cnt+1);
  s7s.print(tempString);
  if(state[cnt]==1){
    blinkstate();
  }
  delay(600);
}

void selectsemi(int k){
  digitalWrite(spot[cnt],HIGH);
  blinkstate();
  delay(k);
  digitalWrite(spot[cnt],LOW);
  s7s.write(0x76);
  s7s.print(tempString);
  delay(500);
}
void selectfull(){  
  if(state[cnt]==0){
    digitalWrite(spot[cnt],HIGH);
    blinkstate();
    state[cnt]=1;
  }
  else if(state[cnt]==1){
    digitalWrite(spot[cnt],LOW); 
    s7s.print(tempString);
   state[cnt]=0;
  }
 
  delay(500);
}
void blinkstate(){
  s7s.write(0x7B);
  s7s.write(0b01001001);
}
void Check_Protocol(char inStr[]){  
  if(!strcmp(inStr,"scrollf")){
    scrollf();
    for(int i=0;i<11;i++){
      inStr[i]=0;
    }
  }
  else if(!strcmp(inStr,"scrollb")){    
    scrollb();
    for(int i=0;i<11;i++){
      inStr[i]=0;
    }
  }
  else if(!strcmp(inStr,"selectsemi")){ 
    if(cnt>=0 && cnt<=9){
      selectsemi(500);
    }
    else if(cnt>=10 && cnt<=19){
      selectfull(); 
    }
    for(int i=0;i<11;i++){
      inStr[i]=0;
    }
  }
  else if(!strcmp(inStr,"selectfull")){
    if(cnt>=0 && cnt<=9){
      selectsemi(2000);
    }
    else if(cnt>=10 && cnt<=19){
      selectfull(); 
    }
    for(int i=0;i<11;i++){
      inStr[i]=0;
    }
  }
  else {
    for(int i=0;i<11; i++){
      inStr[i]=0;
    }
  }
}

void loop() {
  int i=0;
  if(state[cnt]==0){ 
    sprintf(tempString,"%4d",cnt+1);
    s7s.print(tempString); 
  }
  else if(state[cnt]==1){
   blinkstate();
  }
  if (Serial.available() > 0) {             
    while (Serial.available() > 0) {
        inSerial[i]=Serial.read(); 
        i++;      
    }
    inSerial[i]='\0';
    Check_Protocol(inSerial);
  }
  if(digitalRead(buttonscrollf)==LOW){
    scrollf();
    digitalWrite(buttonscrollf,HIGH);  
  }
   if(digitalRead(buttonscrollb)==LOW){
    scrollb();
    digitalWrite(buttonscrollb,HIGH);  
  }
   if(digitalRead(buttonselectsemi)==LOW){
    if(cnt>=0 && cnt<=9){
      selectsemi(500);
    }
    else if(cnt>=10 && cnt<=19){
      selectfull(); 
    }
    digitalWrite(buttonselectsemi,HIGH);  
  }
  if(digitalRead(buttonselectfull)==LOW){
     if(cnt>=0 && cnt<=9){
      selectsemi(2000);
    }
    else if(cnt>=10 && cnt<=19){
      selectfull(); 
    }
    digitalWrite(buttonselectfull,HIGH);
  }
  
  if(digitalRead(displaybutton)==LOW){
    brightChange();
  }
  delay(50);
}
