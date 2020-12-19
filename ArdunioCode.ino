#include <SoftwareSerial.h>

SoftwareSerial my_serial(10, 11);

void setup() {
  Serial.begin(9600);
  my_serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if(my_serial.available()){
    Serial.write("Found");
    recieveMessage();
  }
}

void recieveMessage(){
  char msg[2];
  msg[0] = my_serial.read();
  msg[1] = my_serial.read();

  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}
