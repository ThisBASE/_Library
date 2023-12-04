#include "KeyControl.h"

KeyControl::KeyControl(uint8_t pinout[12])
{
    // Initialize variables
    for (int i = 0; i < 12; i++)
    {
        pin[i] = pinout[i];
        pinMode(pin[i], OUTPUT);
    }
}

void KeyControl::setTimeDelay(int timeDelay)
{
    timeDelayDefaut = timeDelay;
}

void KeyControl::press(uint8_t pinA, uint8_t pinB, int timeDelay, String c)
{
    if (pressed == false)
    {
        _c = c;
        initTime = millis();
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, HIGH);
        Serial.print("press:  ");
        Serial.println(c);
        pressed = true;
    }

    if (int(millis() - initTime) > timeDelay && (pressed = true) && (c == _c))
    {
        digitalWrite(pinA, LOW);
        digitalWrite(pinB, LOW);
        Serial.println("no");
        pressed = false;
    }
}

void KeyControl::pressPlussign()
{
    String c ="+";
    press(pin[0], pin[6], timeDelayDefaut,c);
}
void KeyControl::pressNine()
{
    String c ="9";
    press(pin[1], pin[6], timeDelayDefaut,c);
}
void KeyControl::pressEight()
{
    String c ="8";
    press(pin[2], pin[6], timeDelayDefaut,c);
}
void KeyControl::pressSeven()
{
    String c ="7";
    press(pin[3], pin[6], timeDelayDefaut,c);
}
void KeyControl::pressSix()
{
    String c ="6";
    press(pin[1], pin[7], timeDelayDefaut,c);
}
void KeyControl::pressFive()
{
    String c ="5";
    press(pin[2], pin[7], timeDelayDefaut,c);
}
void KeyControl::pressFour()
{
    String c ="4";
    press(pin[3], pin[7], timeDelayDefaut,c);
}
void KeyControl::pressBackspace()
{
    String c =" ";
    press(pin[4], pin[7], timeDelayDefaut,c);
}
void KeyControl::press000()
{
    String c ="000";
    press(pin[5], pin[7], timeDelayDefaut,c);
}
void KeyControl::pressEnter()
{
    String c ="Enter";
    press(pin[0], pin[8], timeDelayDefaut,c);
}
void KeyControl::pressThree()
{
    String c ="3";
    press(pin[1], pin[8], timeDelayDefaut,c);
}
void KeyControl::pressTwo()
{
    String c ="2";
    press(pin[2], pin[8], timeDelayDefaut,c);
}
void KeyControl::pressOne()
{
    String c ="1";
    press(pin[4], pin[8], timeDelayDefaut,c);
}
void KeyControl::pressPeriod()
{
    String c = ".";
    press(pin[1], pin[9], timeDelayDefaut, c);
}
void KeyControl::pressZero()
{
    String c = "0";
    press(pin[2], pin[9], timeDelayDefaut, c);
}
void KeyControl::pressAsterisk()
{
    String c ="*";
    press(pin[1], pin[10], timeDelayDefaut,c);
}
void KeyControl::pressSlash()
{
    String c ="/";
    press(pin[2], pin[10], timeDelayDefaut,c);
}
void KeyControl::pressNumlock()
{
    String c ="Numlock";
    press(pin[3], pin[10], timeDelayDefaut,c);
}
void KeyControl::pressHyphen()
{
    String c ="-";
    press(pin[1], pin[11], timeDelayDefaut,c);
}
void KeyControl::pressNothing() {}

void KeyControl::press(String c)
{
    if (c == "+")
        pressPlussign();
    else if (c == "9")
        pressNine();
    else if (c == "8")
        pressEight();
    else if (c == "7")
        pressSeven();
    else if (c == "6")
        pressSix();
    else if (c == "5")
        pressFive();
    else if (c == "4")
        pressFour();
    else if (c == " ")
        pressBackspace();
    else if (c == "000")
        press000();
    else if (c == "Enter")
        pressEnter();
    else if (c == "3")
        pressThree();
    else if (c == "2")
        pressTwo();
    else if (c == "1")
        pressOne();
    if (c == ".")
        pressPeriod();
    else if (c == "0")
        pressZero();
    else if (c == "*")
        pressAsterisk();
    else if (c == "/")
        pressSlash();
    else if (c == "Numl")
        pressNumlock();
    else if (c == "-")
        pressHyphen();
    else
        pressNothing();
}