int NextPage(int add){
  int min = 0;
  int max = 0;

  if(isMainMenu){
    max = 1;
  }else if(isIngridentsMenu){
    max = 5;
  }else if(isChanginIngridentMenu){
    max = 3;
  }

  currentPage += add;
  if(currentPage < 0){
    currentPage = max;
  }else if(currentPage > max){
    currentPage = 0;
  }
  return currentPage;
}

void DisplayScreen(){
  ClearScreen();
  
  if(isMainMenu){
    DisplayMainMenu();
  }else if(isIngridentsMenu){
    DisplayIngridentsMenu();
  }else if(isChanginIngridentMenu){
    DisplayIngridentsChangeMenu();
  }else if(listeningMessageMenu){
    DisplayReivedMessagePage();
  }
}

void ClearScreen(){
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
