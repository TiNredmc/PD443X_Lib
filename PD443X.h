#ifndef   PD443X_h
#define   PD443X_h

#include "Arduino.h"

class PD443X
{
public:
     PD443X(int Adr0,int Adr1,int Adr2,int CE,int RST,int WR,int latch,int clock,int data);//set pinout
     void SendByte(char a,byte column); //send individually ascii to individually digit on display
     void ClrDisp();//clear display by using controlWord
     void SendStringScroll(String text,int Speed);//send text string and set scrolling speed
     void SetBrigthness(int B);/set brigthness 0 1 2 3 (0,25,50,100)
     void CtrlWord(char X);//special controlWord (See in datasheet)
     void LampTest(int tog);// 1 to run lamptest 0 to exit lamp test
private:
  int _Adr0;
  int _Adr1;
  int _Adr2;
  int _CE;
  int _WR;
  int _RST;
  int _latch;
  int _clock;
  int _data;
};

#endif
