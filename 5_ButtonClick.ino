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
  }else if(isMainMenu && currentPage ==  2){
    RecipeListMenu = true;
    isMainMenu = false;
  }else if(RecipeListMenu && currentPage == 0){
    RecipeListMenu = false;
    createNewNameMenu = true;
    currentRecipe.Clear();
  }else if(createNewNameMenu){
    currentPos++;
    currentName += alapbet[currentPage];
  }

  currentPage = 0;
  DisplayScreen();
}

void Button3_DoubleClick(){
  if(createNewNameMenu){
    currentPos = 0;
    currentName += alapbet[currentPage];
    currentRecipe.Add(currentName);
    currentName = "";
    createNewNameMenu = false;
    mainPageForNewRecipe = true;
  }
  
  currentPage = 0;
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
  }else if(RecipeListMenu){
    RecipeListMenu = false;
    isMainMenu = true;
  }else if(createNewNameMenu){
    RecipeListMenu = true;
    createNewNameMenu = false;
    currentName = "";
    currentPos = 0;
  }else if(mainPageForNewRecipe){
    mainPageForNewRecipe = false;
    isMainMenu = true;
    currentName = "";
    currentPos = 0;
    recipeMasterList.Add(currentRecipe);
  }
  DisplayScreen();
}
