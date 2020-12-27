void SaveAllDataToEEPRom(){
//  writeString(0,pumpOneLquid);
//  writeString(20,pumpTwoLquid);
//  writeString(40,pumpThreeLquid);
//  writeString(60,pumpFourLquid);
//  writeString(80,pumpFiveLquid);
//  writeString(100,pumpSixLquid);
}

void LoadAllDataFromEEPROM(){
// pumpOneLquid = read_String(0);
// pumpTwoLquid = read_String(20);
// pumpThreeLquid = read_String(40);
// pumpFourLquid = read_String(60);
// pumpFiveLquid = read_String(80);
// pumpSixLquid = read_String(100);
}

void writeString(int add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');
}

String read_String(char add)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
