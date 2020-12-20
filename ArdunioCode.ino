#include <SoftwareSerial.h>

SoftwareSerial my_serial(10, 11);

String pumpOneLquid = "Empty";
String pumpTwoLquid = "Empty";
String pumpThreeLquid = "Empty";
String pumpFourLquid = "Empty";
String pumpFiveLquid = "Empty";
String pumpSixLquid = "Empty";

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  my_serial.begin(9600);  
}

void loop() {
  if(my_serial.available()){
    recieveMessage();
  }
}

void recieveMessage(){
  char msg[2];
  msg[0] = my_serial.read();
  msg[1] = my_serial.read();

  if(msg[0] == 'A'){
    CreatePumpMessage(pumpOneLquid,pumpTwoLquid,pumpThreeLquid,pumpFourLquid,pumpFiveLquid,pumpSixLquid);
  }
}

void sendMessage(const char *data, int l){
  byte len[4];
  len[0] = 85; //preamble
  len[1] = 85; //preamble
  len[2] = (l >> 8) & 0x000000FF;
  len[3] = (l & 0x000000FF);
  my_serial.write(len, 4);
  my_serial.flush();
  my_serial.write(data);
  my_serial.flush();
}

//A = Send back what liquids are set in each pump
//a = set the liquids which are in each pump
