//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(7,6);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

//Variable Define
int Data[9];
void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);

  //Set Power Level
  radio.setPALevel(RF24_PA_MAX);

  //Set Data Rate
  radio.setDataRate(RF24_250KBPS);
  
  //Set module as receiver
  radio.startListening();
  Serial.println("Hello World");
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    radio.read(&Data, sizeof(Data));
    Serial.println("Data:");
    Serial.println(Data[0]);
    Serial.println(Data[1]);
    Serial.println(Data[2]);
    Serial.println(Data[3]);
    Serial.println(Data[4]);
    Serial.println(Data[5]);
    Serial.println(Data[6]);
    Serial.println(Data[7]);
    Serial.println(Data[8]);
  }
}
