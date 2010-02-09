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

  short a=0, b=0, i=0, out=0;
  unsigned char j=0, k=0;
  unsigned char outs[20];
 
  
  TimerInit ();
 
  DDRB = 0xF0;
  PUCR = 0X02;
  DDRP = 0X00;
  ATD0CTL2 = 0X80;
  ATD0CTL3 = 0X06;
  ATD0CTL4 = 0X83;
  ATD0CTL5 = 0XA0;
  ATD0DIEN = 0X01;


  i=0;
  while(1)
  {
    
      b = PORTAD0_PTAD0;
      a = ATD0DR0;
     
      if(!(PTIP & 1) ){
        outs[i] = a;
        i=i+1;
        if(i>19) i=0;
        mswait(100);
      }

  }
 

  EnableInterrupts;

 
}