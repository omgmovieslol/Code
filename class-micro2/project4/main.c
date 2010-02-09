#include <hidef.h>           /* common defines and macros */
#include <mc9s12dt256.h>     /* derivative information */
#include <math.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dt256b"



#define   Rref            10000
#define   A1              3.354016E-03
#define   B1              2.569850E-04
#define   C1              2.620131E-06
#define   D1              6.383091E-08




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

  short a=0, b=0, i=0, out=0;
  unsigned char j=0, k=0;
  unsigned char outs[20];
   int table [50] = { 295 , 244 , 216 , 198 , 184 , 172 , 163 , 154 , 147 , 141 , 135 , 129 , 124 , 119 , 115 , 110 , 106 , 102 , 99 , 95 , 92 , 88 , 85 , 81 , 78 , 75 , 72 , 69 , 65 , 62 , 59 , 56 , 53 , 49 , 46 , 42 , 39 , 35 , 32 , 28 , 23 , 19 , 14 , 9 , 3 , -2 , -10 , -19 , -31 , -50 };
 
  
  TimerInit ();
 
  DDRB = 0xF0;
  PUCR = 0X02;
  DDRP = 0X00;
  DDRT = 0XFF;
  ATD0CTL2 = 0X80;
  ATD0CTL3 = 0X06;
  ATD0CTL4 = 0X83;
  ATD0CTL5 = 0XA0;
  ATD0DIEN = 0X01;


  while(1)
  {
    i++;
    if(i > 19)
      i=0; 
   
    b = PORTAD0_PTAD0;
    a = ATD0DR0;
    
    outs[i] = table[a/5];
   
    for(j=0; j<5; j++) {
      
      
      if(!(PTIP & 1) ){

        for(k=i-5;k<i;k++){
          PORTB = 0x00;
          PTT = 0xFF;
          mswait(50);
           PTT = 0x00;
          mswait(50);
          
        }
      } else{
        PORTB = table[a/5];
        mswait(100);
      }
      
    }


  }
 

  EnableInterrupts;

 
}