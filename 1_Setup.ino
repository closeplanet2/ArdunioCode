void setup() {
  Serial.begin(9600);
  my_serial.begin(9600);  
  lcd.begin(16, 2);
  DisplayScreen();

  buttonOne.attachClick(Button1);  
  buttonTwo.attachClick(Button2);  
  buttonThree.attachClick(Button3); 
  buttonFour.attachClick(Button4); 
  buttonThree.attachDoubleClick(Button3_DoubleClick);

  pinMode(13, OUTPUT);

  LoadAllDataFromEEPROM();
}
