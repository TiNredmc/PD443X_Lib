int Adr0 = 4;     //address 0 
int Adr1 = 5;     //address 1
int Adr2 = 6;     //address 2
int CE   = 7;     //chip enable
int RST  = 8;     //Reset
int WR   = 9;     //Write 
int latch = 10;   //595 latch
int clock = 13;   //595 clock
int data  = 12;   //595 data 

void sendByte(byte d)
{
digitalWrite(latch,LOW);
shiftOut(data,clock,MSBFIRST,d);
digitalWrite(latch,HIGH);
}

void setAddr(int adr)
{
digitalWrite(Adr0,(adr&0x1));
digitalWrite(Adr1,(adr&0x2));
digitalWrite(Adr2,(adr&0x4));
}
void putChar(int pos,byte ch)
{
digitalWrite(CE,LOW);
setAddr(pos);
sendByte(ch);
digitalWrite(WR,LOW);
digitalWrite(WR,HIGH);
digitalWrite(CE,HIGH);
}
void setup ()
{
pinMode(latch ,OUTPUT);
pinMode(clock ,OUTPUT);
pinMode(data  ,OUTPUT);
pinMode(Adr0  ,OUTPUT);
pinMode(Adr1  ,OUTPUT);
pinMode(Adr2  ,OUTPUT);
pinMode(WR    ,OUTPUT);
pinMode(CE    ,OUTPUT);
pinMode(RST   ,OUTPUT);

//Reset PD4437
digitalWrite(CE ,HIGH);
digitalWrite(WR ,HIGH);
digitalWrite(RST,HIGH);
putChar(0,0x40);
delay(500);
putChar(0,0x80);
}
void loop()
{
putChar(7,'T');
putChar(6,'i');
putChar(5,'N');
putChar(4,'!');
delay(500);
putChar(0,0x18);
putChar(7,0x7f);
putChar(6,0x7f);
putChar(5,0x7f);
putChar(4,0x7f);
delay(500);
putChar(0,0x80);
}

