void CreatePumpMessage(String one, String two, String three, String four, String five, String six ){
  char charBufone[one.length()];
  char charBuftwo[two.length()];
  char charBufthree[three.length()];
  char charBuffour[four.length()];
  char charBuffive[five.length()];
  char charBufsix[six.length()];
  
  one.toCharArray(charBufone, one.length());
  two.toCharArray(charBuftwo, two.length());
  three.toCharArray(charBufthree, three.length());
  four.toCharArray(charBuffour, four.length());
  five.toCharArray(charBuffive, five.length());
  six.toCharArray(charBufsix, six.length());

  int size = one.length() + 4 + two.length() + 4 + three.length() + 4 + four.length() + 4 + five.length() + 4 + six.length() + 4;
  char dest[size];
  strcpy(dest, charBufone);
  strcat(dest, ";");
  strcpy(dest, charBuftwo);
  strcat(dest, ";");
  strcpy(dest, charBufthree);
  strcat(dest, ";");
  strcpy(dest, charBuffour);
  strcat(dest, ";");
  strcpy(dest, charBuffive);
  strcat(dest, ";");
  strcpy(dest, charBufsix);
  strcat(dest, ";");

  sendMessage(dest,size);
}
