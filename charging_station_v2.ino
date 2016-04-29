#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Time.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte ROWS = 3; //use 3 rows
const byte COLS = 3; //3 columns
//Keymap:
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};
byte rowPins[ROWS] = {8, 7, 6};
byte colPins[COLS] = {13, 10, 9};
String person_1, person_2, person_3, person_4, person_5, person_6, person_7, person_8;
boolean phone_1 = false, phone_2 = false, phone_3 = false, phone_4 = false, phone_5 = false, phone_6 = false, phone_7 = false, phone_8 = false;
long timeBefore_1, timeBefore_2, timeBefore_3, timeBefore_4, timeBefore_5, timeBefore_6, timeBefore_7, timeBefore_8, timeNow_1, timeNow_2, timeNow_3, timeNow_4, timeNow_5, timeNow_6, timeNow_7, timeNow_8;
//initialize keypad
Keypad customKeyPad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  lcd.print("TsunamiSolutions");
  char key = customKeyPad.waitForKey();
  if (key)
  {
    switch (key)
    {
      case '1':
          timeNow_1 = (day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
          if (timeBefore_1 == 0) {
            textDisplay("iPhone 4s Ver. 9.3.1" + person_1);//Update here
          }
          else {
            textDisplay("iPhone 4s Ver. 9.3.1" + person_1 + " " + timeString(timeNow_1, timeBefore_1));//Update here
          }
          break;
      case '2':
          timeNow_2 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
          if (timeBefore_2 == 0) {
            textDisplay("iPhone 5c Ver. 9.3.1" + person_2);  //Update here
          }
          else {
            textDisplay("iPhone 5c Ver. 9.3.1" + person_2 + " " + timeString(timeNow_2, timeBefore_2));  //Update here
          }
          break;
      case '3':
          timeNow_3 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
          if (timeBefore_3 == 0) {
            textDisplay("Moto G Ver. 5.1" + person_3);  //Update here
          }
          else {
            textDisplay("Moto G Ver. 5.1" + person_3 + " " + timeString(timeNow_3, timeBefore_3));  //Update here
          }
          break;
      case '4':
          timeNow_4 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
          if (timeBefore_4 == 0) {
            textDisplay("BlackBerry Z10 Ver. 10.3.2.2474" + person_4);  //Update here
          }
          else {
            textDisplay("BlackBerry Z10 Ver. 10.3.2.2474" + person_4 + " " + timeString(timeNow_4, timeBefore_4));  //Update here
          }
          break;
      case '5':
          timeNow_5 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
          if (timeBefore_5 == 0) {
            textDisplay("BlackBerry Passport Ver. 10.3.2.2474" + person_5);  //Update here
          }
          else {
            textDisplay("BlackBerry Passport Ver. 10.3.2.2474" + person_5 + " " + timeString(timeNow_5, timeBefore_5));  //Update here
          }
          break;
      case '6':
          timeNow_6 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
          if (timeBefore_6 == 0) {
            textDisplay("HTC Ver. 4.0.3" + person_6);  //Update here
          }
          else {
            textDisplay("HTC Ver. 4.0.3" + person_6 + " " + timeString(timeNow_6, timeBefore_6));  //Update here
          }
          break;
      case '7':
          timeNow_7 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
          if (timeBefore_7 == 0) {
            textDisplay("Samsung Nexus Ver. 5.0" + person_7);  //Update here
          }
          else {
            textDisplay("Samsung Nexus Ver. 5.0" + person_7 + " " + timeString(timeNow_7, timeBefore_7));  //Update here
          }
          break;
      case '8':
          timeNow_8 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
          if (timeBefore_8 == 0) {
            textDisplay("SafetyLine" + person_8);  //Update here
          }
          else {
            textDisplay("SafetyLine" + person_8 + " " + timeString(timeNow_8, timeBefore_8));  //Update here
          }
          break;
      case '9':
          configurationMode();
          break;
      default:
          lcd.print("default");
    }
          
 }
 lcd.clear();
}

int textDisplay(String arg) {
  //detect the length of string
  int len = arg.length();
  lcd.clear();
  //lcd.setCursor(0,1);
  if (len <= 16) {
    lcd.setCursor(0,0);
    lcd.print("TsunamiSolutions");
    lcd.setCursor(0,1);
    lcd.print(arg);
  }
  else {
    lcd.print(arg);
    for (int positionCounter = 0; positionCounter <= len - 16; positionCounter++) {
      lcd.setCursor(0,0);
      lcd.print("TsunamiSolutions");
      lcd.setCursor(0,1);
      lcd.print(arg.substring(positionCounter));
      delay(300);
    }
    /*for (int positionCounter = 0; positionCounter < len + 16; positionCounter++) {
      lcd.scrollDisplayRight();
      delay(200);
    }
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(200);
    }*/
  }
  delay(2000);
  return 0;
}

int configurationMode() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please Enter Pin: ");
  lcd.setCursor(0,1);
  String passcode = "";
  boolean stringComplete = false;
  while (stringComplete == false) {
    char pin = customKeyPad.waitForKey();
    lcd.print(pin);
    passcode += pin;
    if (passcode.length() == 4) {
      stringComplete = true;
    }
  }
  if (passcode == "8252") {
    lcd.clear();
    selectSlot("Gabriel");
  }
  else if (passcode == "8686") {
    lcd.clear();
    selectSlot("Kevin");
  }
  else if (passcode == "1717") {
    lcd.clear();
    selectSlot("Jordan");
  }
  else if (passcode == "8812") {
    lcd.clear();
    selectSlot("Joel");
  }
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sorry");
    lcd.setCursor(0,1);
    lcd.print("Incorrect Pin");
    delay(1500);
  }
  passcode = "";
}

int selectSlot(String person) {
  lcd.setCursor(0,0);
  lcd.print("Hi " + person);
  lcd.setCursor(0,1);
  lcd.print("Which Phone?");
  char slotNum = customKeyPad.waitForKey();
  if (slotNum)
  {
    switch (slotNum)
    {
      case '1':
          if (phone_1 == false) {
            person_1 = " " + person;
            phone_1 = true;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 1 has been");
            lcd.setCursor(0,1);
            lcd.print("checked out");
            timeBefore_1 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
            delay(1500);
          }
          else {
            person_1 = "";
            phone_1 = false;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 1 has been");
            lcd.setCursor(0,1);
            lcd.print("checked in");
            timeBefore_1 = 0;
            delay(1500);
          }
          break;
      case '2':
          if (phone_2 == false) {
            person_2 = " " + person;
            phone_2 = true;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 2 has been");
            lcd.setCursor(0,1);
            lcd.print("checked out");
            timeBefore_2 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
            delay(1500);
          }
          else {
            person_2 = "";
            phone_2 = false;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 2 has been");
            lcd.setCursor(0,1);
            lcd.print("checked in");
            timeBefore_2 = 0;
            delay(1500);
          }
          break;
      case '3':
          if (phone_3 == false) {
            person_3 = " " + person;
            phone_3 = true;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 3 has been");
            lcd.setCursor(0,1);
            lcd.print("checked out");
            timeBefore_3 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
            delay(1500);
          }
          else {
            person_3 = "";
            phone_3 = false;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 3 has been");
            lcd.setCursor(0,1);
            lcd.print("checked in");
            timeBefore_3 = 0;
            delay(1500);
          }
          break;
      case '4':
          if (phone_4 == false) {
            person_4 = " " + person;
            phone_4 = true;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 4 has been");
            lcd.setCursor(0,1);
            lcd.print("checked out");
            timeBefore_4 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
            delay(1500);
          }
          else {
            person_4 = "";
            phone_4 = false;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 4 has been");
            lcd.setCursor(0,1);
            lcd.print("checked in");
            timeBefore_4 = 0;
            delay(1500);
          }
          break;
      case '5':
          if (phone_5 == false) {
            person_5 = " " + person;
            phone_5 = true;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 5 has been");
            lcd.setCursor(0,1);
            lcd.print("checked out");
            timeBefore_5 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
            delay(1500);
          }
          else {
            person_5 = "";
            phone_5 = false;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 5 has been");
            lcd.setCursor(0,1);
            lcd.print("checked in");
            timeBefore_5 = 0;
            delay(1500);
          }
          break;
      case '6':
          if (phone_6 == false) {
            person_6 = " " + person;
            phone_6 = true;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 6 has been");
            lcd.setCursor(0,1);
            lcd.print("checked out");
            timeBefore_6 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
            delay(1500);
          }
          else {
            person_6 = "";
            phone_6 = false;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 6 has been");
            lcd.setCursor(0,1);
            lcd.print("checked in");
            timeBefore_6 = 0;
            delay(1500);
          }
          break;
      case '7':
          if (phone_7 == false) {
            person_7 = " " + person;
            phone_7 = true;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 7 has been");
            lcd.setCursor(0,1);
            lcd.print("checked out");
            timeBefore_7 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
            delay(1500);
          }
          else {
            person_7 = "";
            phone_7 = false;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 7 has been");
            lcd.setCursor(0,1);
            lcd.print("checked in");
            timeBefore_7 = 0;
            delay(1500);
          }
          break;
      case '8':
          if (phone_8 == false) {
            person_8 = " " + person;
            phone_8 = true;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 8 has been");
            lcd.setCursor(0,1);
            lcd.print("checked out");
            timeBefore_8 =(day() - 1) * 86400 + hour() * 3600 + minute() * 60 + second();
            delay(1500);
          }
          else {
            person_8 = "";
            phone_8 = false;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Phone 8 has been");
            lcd.setCursor(0,1);
            lcd.print("checked in");
            timeBefore_8 = 0;
            delay(1500);
          }
          break;
      default:
          lcd.clear();
          lcd.setCursor(5,0);
          lcd.print("Error!");
          delay(1000);
    }
          
 }
}

String timeString(long timeNow, long timeBefore) {
    String displayString;
    int d, h, m, s;
    long timeBorrow = timeNow - timeBefore;
    d = timeBorrow / 86400;
    h = (timeBorrow - 86400 * d) / 3600;
    m = (timeBorrow - 86400 * d - 3600 * h) / 60;
    s = timeBorrow - (d * 86400) - (h * 3600) - (m * 60);
    if (timeBorrow < 60 ) {
      displayString = String(s) + "s";
    }
    else if (timeBorrow >= 60 && timeBorrow < 3600) {
      displayString = String(m) + "m";
    }
    else if (timeBorrow >= 3600 && timeBorrow < 86400) {
      displayString = String(h) + "h";
    }
    else {
      displayString = String(d) + "day";
    }
    return displayString;
}
