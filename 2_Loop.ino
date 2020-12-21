void loop() {
  CheckButtons();
  
  if(my_serial.available()){
    recieveMessage();
  }
}
