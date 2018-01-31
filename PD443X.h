#ifndef   PD443X_h
#define   PD443X_h

#include "Arduino.h"

class PD443X
{
public:
     PD443X(int Adr0,int Adr1,int Adr2,int CE,int RST,int               WR,int latch,int clock,int data);
     void SendByte(char a,byte column); 
     void ClrDisp();
     void SendStringScroll(String text,int Speed);
     void SetBrigthness(int B);
     void CtrlWord(char X);
     void LampTest(int tog);
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
