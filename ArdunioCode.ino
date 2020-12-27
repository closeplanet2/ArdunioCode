#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <OneButton.h>
#include <EEPROM.h>
#include "ListLib.h"

#define MY_SIZE 4
SoftwareSerial my_serial(10, 11);
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
OneButton buttonOne(53, true); 
OneButton buttonTwo(52, true); 
OneButton buttonThree(51, true); 
OneButton buttonFour(50, true); 

String alapbet[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","_"};
String ingridents[] = {"Empty","Vodka","Rum", "Cider"};
List<List<String>> recipeMasterList;
List<String> currentRecipe;
String currentName = "";
int currentPos = 0;

int currentPage = 0;
int changingIngrident;

boolean isMainMenu = true;
boolean isIngridentsMenu = false;
boolean isChanginIngridentMenu = false;
boolean listeningMessageMenu = false;
boolean RecipeListMenu = false;
boolean createNewNameMenu = false;
boolean mainPageForNewRecipe = false;

String pumpOneLquid = "Empty";
String pumpTwoLquid = "Empty";
String pumpThreeLquid = "Empty";
String pumpFourLquid = "Empty";
String pumpFiveLquid = "Empty";
String pumpSixLquid = "Empty";

void SetPump(String val){
  switch (changingIngrident) {
      case 0:
        pumpOneLquid = val;
        break;
      case 1:
        pumpTwoLquid = val;
        break;
      case 2:
        pumpThreeLquid = val;
        break;
      case 3:
        pumpFourLquid = val;
        break;
      case 4:
        pumpFiveLquid = val;
        break;
      case 5:
        pumpSixLquid = val;
        break;
      default:
        lcd.setCursor(0, 0);
        lcd.print("Error!");
      break;
   }
  SaveAllDataToEEPRom();
}
