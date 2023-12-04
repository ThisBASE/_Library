#ifndef KEYCONTROL_H
#define KEYCONTROL_H
#include <Arduino.h>
class KeyControl
{
public:
  // Constructor
  KeyControl(uint8_t pin[12]);


  // Methods
  void setTimeDelay(int t);
  void press(uint8_t pinA, uint8_t pinB);
  void press(uint8_t pinA, uint8_t pinB, int timeDelay,String c);
  void press(String c);
  void pressPlussign();  //"+"
  void pressNine();      //"9"
  void pressEight();     //"8"
  void pressSeven();     //"7"
  void pressSix();       //"6"
  void pressFive();      //"5"
  void pressFour();      //"4"
  void pressBackspace(); //"backspace"
  void press000();       //"000"
  void pressEnter();     //"Enter"
  void pressThree();     //"3"
  void pressTwo();       //"2"
  void pressOne();       //"1"
  void pressPeriod();    //"."
  void pressZero();      //"0"
  void pressAsterisk();  //"*"
  void pressSlash();     //"/"
  void pressNumlock();   //"Numlock"
  void pressHyphen();    //"-"
  void pressNothing();

private:
  // Variables
  unsigned long initTime;
  int timeDelayDefaut = 100;
  uint8_t pin[12];
  String key;
  bool pressed = false;
  String _c;
};

#endif