#include <hidef.h>           /* common defines and macros */
#include <mc9s12dt256.h>     /* derivative information */
#include <math.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dt256b"

void TimerInit(void) {
  COPCTL = 0x00;
  DDRT |= 0x40;
  TIOS |= 0x20;
  TSCR1 = 0x80;
}

void mswait(unsigned int time) {
  for(; time > 0; time--) {
    TC5 = TCNT + 2000;
    TFLG1 = 0x20;
    while((TFLG1 & 0x20) == 00) { };
  }
}

/* MAIN PROGRAM */
void main(void)
{

  short i=0;
  // 16 bit table
  long table [50] = { 295 , 244 , 216 , 198 , 184 , 172 , 163 , 154 , 147 , 141 , 135 , 129 , 124 , 119 , 115 , 110 , 106 , 102 , 99 , 95 , 92 , 88 , 85 , 81 , 78 , 75 , 72 , 69 , 65 , 62 , 59 , 56 , 53 , 49 , 46 , 42 , 39 , 35 , 32 , 28 , 23 , 19 , 14 , 9 , 3 , -2 , -10 , -19 , -31 , -50 };
 
  
  TimerInit ();
 
  DDRB = 0xF0;
  DDRA = 0xF0;
  PUCR = 0X02;
  DDRP = 0X00;
  DDRT = 0XFF;


  while(1)
  {
    for(i=0;i<50;i++){
      // assume table is 16 bits, ignore first 4 bits.
      PORTB=table[i]<<4; // portb first 8
      PORTA=table[i]<<12; // port a last 4
      mswait(1);
    }
  }
 

  EnableInterrupts;

 
}