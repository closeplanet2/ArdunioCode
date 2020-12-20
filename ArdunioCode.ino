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
}
