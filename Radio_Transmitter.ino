//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(2,3);  // CE, CSN


//address through which two modules communicate.
const byte address[6] = "00001";

//Pin Define
int JSR_x=A0; //Joy Stick Right (x-Axis)
int JSR_y=A1; //Joy Stick Right (y-Axis)
int JSL_x=A2; //Joy Stick Left (x-Axis)
int JSL_y=A3; //Joy Stick Left (y-Axis)
int PotPin=A7; //Potentiometer 
int PushButton1=4; //Push Button 1
int PushButton2=5; //Push Button 2
int PushButton3=6; //Push Button 3
int PushButton4=7; //Push Button 4

// Data storing Variable
int Data[9];

void setup() {
  // put your setup code here, to run once:

  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);

  //Set Power Level
  radio.setPALevel(RF24_PA_MAX);

  //Set Data Rate
  radio.setDataRate(RF24_250KBPS);
  
  //Set module as transmitter
  radio.stopListening();
  
  //Pin Mode
pinMode(JSR_x,INPUT);
pinMode(JSR_y,INPUT);
pinMode(JSL_x,INPUT);
pinMode(JSL_y,INPUT);
pinMode(PotPin,INPUT);
pinMode(PushButton1,INPUT);
pinMode(PushButton2,INPUT);
pinMode(PushButton3,INPUT);
pinMode(PushButton4,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read all data
 Data[0]=analogRead(JSR_x);
 Data[1]=analogRead(JSR_y);
 Data[2]=analogRead(JSL_x);
 Data[3]=analogRead(JSL_y);
 Data[4]=analogRead(PotPin);
 Data[5]=digitalRead(PushButton1);
 Data[6]=digitalRead(PushButton2);
 Data[7]=digitalRead(PushButton3);
 Data[8]=digitalRead(PushButton4);
 radio.write(&Data, sizeof(Data));
delay(2000);
}
