void CheckButtons(){
  buttonOne.tick();  
  buttonTwo.tick();  
  buttonThree.tick();  
  buttonFour.tick(); 
}

void Button1(){
  currentPage = NextPage(-1);
  DisplayScreen();
}

void Button2(){
  currentPage = NextPage(1);
  DisplayScreen();
}

void Button3(){
  if(isMainMenu && currentPage == 0){
    isMainMenu = false;
    isIngridentsMenu = true;
  }else if(isIngridentsMenu){
    changingIngrident = currentPage;
    currentPage = 0;
    isChanginIngridentMenu = true;
    isIngridentsMenu = false;
  }else if(isChanginIngridentMenu){
    SetPump(ingridents[currentPage]);
    currentPage = changingIngrident;
    isChanginIngridentMenu = false;
    isIngridentsMenu = true;
  }else if(isMainMenu && currentPage == 1){
    listeningMessageMenu = true;
    isMainMenu = false;
  }
  DisplayScreen();
}

void Button4(){
  if(isIngridentsMenu){
    currentPage = 0;
    isMainMenu = true;
    isIngridentsMenu = false;
  }else if(isChanginIngridentMenu){
    currentPage = changingIngrident;
    isChanginIngridentMenu = false;
    isIngridentsMenu = true;
  }else if(listeningMessageMenu){
     isMainMenu = true;
     listeningMessageMenu = false;
  }
  DisplayScreen();
}
