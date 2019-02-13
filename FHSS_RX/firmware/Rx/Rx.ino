#include<SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
RF24 radio(9,10);
const uint64_t addr=0xf1f1f1f1f1LL;
byte data,ack=18;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
radio.begin();

radio.enableAckPayload();

radio.setDataRate(RF24_250KBPS);
radio.openReadingPipe(1,addr);
radio.startListening();
radio.setChannel(100);
}

void loop() {
 
if(radio.available()){
  radio.read(&data,sizeof(data));
  radio.writeAckPayload(1,&ack,sizeof(ack));
  Serial.println(data);
  ack++;
  }
  
}
