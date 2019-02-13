#include<SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
RF24 radio(9,10);
const uint64_t addr=0xf1f1f1f1f1LL;
byte data=100,ack;
void setup() {
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
radio.begin();

radio.enableAckPayload();
radio.setDataRate(RF24_250KBPS);
radio.openWritingPipe(addr);
radio.setChannel(100);
}

void loop() {
  
  if(digitalRead(7)==HIGH){
    data=0xff;
    }
    else if(digitalRead(7)==LOW){
      data=0x00;
      }
  
  // put your main code here, to run repeatedly:
if(radio.write(&data,sizeof(data))){
  if(radio.isAckPayloadAvailable()){
    radio.read(&ack,sizeof(ack));
    
    }
    Serial.println(ack);
  
  }



}
