#include "Arduino.h"
#include "PD443X.h"

  int _Adr0;
  int _Adr1;
  int _Adr2;
  int _CE;
  int _WR;
  int _RST;
  int _latch;
  int _clock;
  int _data;

PD443X::PD443X(int Adr0,int Adr1,int Adr2,int CE,int RST,int               WR,int latch,int clock,int data)
{
_Adr0 = Adr0;
_Adr1 = Adr1;
_Adr2 = Adr2;
_CE   = CE;
_RST  = RST;
_WR   = WR;
_latch = latch;
_clock = clock;
_data  = data;

pinMode(Adr0,OUTPUT);
pinMode(Adr1,OUTPUT);
pinMode(Adr2,OUTPUT);
pinMode(CE  ,OUTPUT);
pinMode(RST ,OUTPUT);
pinMode(WR  ,OUTPUT);
pinMode(latch,OUTPUT);
pinMode(clock,OUTPUT);
pinMode(data ,OUTPUT);
}

void PD443X::SendByte(char a,byte column)
{
digitalWrite(_WR,LOW);
digitalWrite(_CE,LOW);
digitalWrite(_Adr2,HIGH);
digitalWrite(_Adr0, column >> 0& B1);
digitalWrite(_Adr1, column >> 1& B1);
digitalWrite(_latch,LOW);
shiftOut(_data,_clock,MSBFIRST,a);
digitalWrite(_latch,HIGH);
digitalWrite(_WR,HIGH);
digitalWrite(_CE,HIGH);
digitalWrite(_Adr2,LOW);
}

void PD443X::ClrDisp()
{
digitalWrite(_WR,LOW);
digitalWrite(_CE,LOW);
digitalWrite(_Adr2,LOW);
digitalWrite(_latch,LOW);
shiftOut(_data,_clock,MSBFIRST,0x80);
digitalWrite(_latch,HIGH);
digitalWrite(_WR,HIGH);
digitalWrite(_CE,HIGH);
digitalWrite(_Adr2,HIGH);
}

void PD443X::SendStringScroll(String text ,int Speed)
{
ClrDisp();
text="    "+text+"    ";
int l = text.length()+1;
byte b[1];
text.getBytes(b,l);
for(int i=0;i < l-4;i++)
{
SendByte(b[0+i],3);
SendByte(b[1+i],2);
SendByte(b[3+i],1);
SendByte(b[4+i],0);
delay(Speed);
}
ClrDisp();
}
