//==================================================================
//Arduino Uno (Master)
//==================================================================

#include <SPI.h>
char receivedChar;
int SLAVESELECT=10;
int DD_MOSI=11;
int DD_MISO=12;
int DD_SCK=13;
byte buffer[6]={0x01,0x02,0x03,0x04,0x05,0x06};

void setup()
{
SPI.begin();
SPI.setClockDivider(SPI_CLOCK_DIV4);
Serial.begin(9600);
pinMode(SLAVESELECT,OUTPUT);
pinMode(DD_MOSI,OUTPUT);
pinMode(DD_MISO,INPUT);
pinMode(DD_SCK,OUTPUT);
digitalWrite(SLAVESELECT,HIGH);
}

void loop(void)
{
//digitalWrite(SLAVESELECT,LOW);  //enable Slave Select
  //for(int i=0;i<6;i++)
  //{
   byte x = SPI.transfer('S');
   //Serial.print("master:");
  // Serial.println(buffer[i], HEX);
   //Serial.println(x, HEX);
   if (Serial.available() > 0) {
receivedChar = Serial.read();
Serial.println(receivedChar);
      
  }
  delay(5000);
//digitalWrite(SS,HIGH);
}