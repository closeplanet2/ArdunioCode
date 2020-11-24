//Main libary to use the bluetooth module
#include <SoftwareSerial.h>

//Set ports for bluetooth on output 10 and 11
SoftwareSerial my_serial(10, 11);

//setup and loop must be included in all projects
void setup() {
  //begin the console and bluetooth module frequency. Must be set the same base is 9600
  Serial.begin(9600);
  my_serial.begin(9600);
}

void loop() {
  //When a message is recived by the bluetooth module, my_serial will become aviable and hold the message stored. It then calls a function to read that message
  if(my_serial.available()){
    recieveMessage();
  }
}

void recieveMessage(){
    //Get the message from the bluetooth module. Data is sent over as a char[] so all data must be put back into a char[]. 
    char msg[2];
    msg[0] = my_serial.read();
    msg[1] = my_serial.read();

    //if the first data in the array is e, send a message back through the bluetooth module.
    if(msg[0] == 'E'){
      //the size is 7 as its the number of letters (char) in the string. A string is simple a char[], so each letter is a different element in the array. R = 0, e = 1, c = 2..... there are 7 elements in the array.
      sendMessage("Recived", 7);
    }
}

void sendMessage(const char *data, int l){
  //this chunk of data must be sent first overwise your message wont be. I dont know why. After you send data you must flush (clear) the outgoing message list otherwise duplication may happen.
  byte len[4];
  len[0] = 85; //preamble
  len[1] = 85; //preamble
  len[2] = (l >> 8) & 0x000000FF;
  len[3] = (l & 0x000000FF);
  my_serial.write(len, 4);
  my_serial.flush();

  //send our data back through the bluetooth module.
  my_serial.write(data);
  my_serial.flush();
}
