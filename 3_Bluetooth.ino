void recieveMessage(){
  char msg[2];
  msg[0] = my_serial.read();
  msg[1] = my_serial.read();

  Serial.write(msg[0]);

  if(msg[0] == 'A'){
    CreatePumpMessage("a;" + pumpOneLquid + ";" + pumpTwoLquid + ";" + pumpThreeLquid + ";" + pumpFourLquid + ";" + pumpFiveLquid + ";" + pumpSixLquid);
  }

  if(msg[0] == 'B'){
    String one = "b;";
    for(int i = 0; i < MY_SIZE; i++){
      one += ingridents[i] + ";";
    }
    CreatePumpMessage(one);
  }
}

void CreatePumpMessage(String data){
  char charBufone[data.length() + 1];
  data.toCharArray(charBufone, data.length() + 1);
  sendMessage(charBufone,data.length() + 1);
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
