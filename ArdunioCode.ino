#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <OneButton.h>

SoftwareSerial my_serial(10, 11);

LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

String pumpOneLquid = "Empty";
String pumpTwoLquid = "Empty";
String pumpThreeLquid = "Empty";
String pumpFourLquid = "Empty";
String pumpFiveLquid = "Empty";
String pumpSixLquid = "Empty";

OneButton buttonOne(53, true); 
OneButton buttonTwo(52, true); 
OneButton buttonThree(51, true); 
OneButton buttonFour(50, true); 

int currentPage = 0;
boolean isMainMenu = true;
boolean isIngridentsMenu = false;
boolean isChanginIngridentMenu = false;
boolean listeningMessageMenu = false;

String ingridents[] = {"Empty","Vodka","Rum", "Cider"};

//What ingrident am i changing?
int changingIngrident;

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
}
