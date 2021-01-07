void DisplayMainMenu(){
  switch (currentPage) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Ingridents!");
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Incoming");
      lcd.setCursor(0, 1);
      lcd.print("Messages!");
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Recipes!");
      break;
    default:
      lcd.setCursor(0, 0);
      lcd.print("Error!");
      break;
  }
}

void DisplayIngridentsMenu(){
  switch (currentPage) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Pump 1:");
      lcd.setCursor(0, 1);
      lcd.print(pumpOneLquid);
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Pump 2:");
      lcd.setCursor(0, 1);
      lcd.print(pumpTwoLquid);
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Pump 3:");
      lcd.setCursor(0, 1);
      lcd.print(pumpThreeLquid);
      break;
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("Pump 4:");
      lcd.setCursor(0, 1);
      lcd.print(pumpFourLquid);
      break;
    case 4:
      lcd.setCursor(0, 0);
      lcd.print("Pump 5:");
      lcd.setCursor(0, 1);
      lcd.print(pumpFiveLquid);
      break;
    case 5:
      lcd.setCursor(0, 0);
      lcd.print("Pump 6:");
      lcd.setCursor(0, 1);
      lcd.print(pumpSixLquid);
      break;
    default:
      lcd.setCursor(0, 0);
      lcd.print("Error!");
      break;
  }
}

void DisplayIngridentsChangeMenu(){
  lcd.setCursor(0, 0);
  lcd.print(ingridents[currentPage]);
}

void DisplayRecipeListPage(){
  if(currentPage == 0){
    lcd.setCursor(0, 0);
    lcd.print("New Recipe!");
  }else{
    lcd.setCursor(0, 0);
    List<String> list = recipeMasterList[currentPage-1];
    String name = list[0];
    Serial.print(name);
    lcd.print(name);
  }
}

void DisplaySetNewNamePage(){
   lcd.setCursor(0, 0);
   lcd.print(currentName);
   lcd.setCursor(currentPos, 0);
   lcd.print(alapbet[currentPage]);
   lcd.setCursor(0, 1);
   String name = "Current:" + alapbet[currentPage];
   lcd.print(name);
}

void DisplayMainMenuForCreateREcipe(){
  lcd.setCursor(0, 0);
  lcd.print(currentRecipe[0]);
}

void DisplayReivedMessagePage(){
   lcd.setCursor(0, 0);
   lcd.print("Message:");
}
