#include <hidef.h>
#include <mc9s12dt256.h>    
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



void main(void)
{

  short a=0, b=0, i=0, out=0;
  int done,start;
  unsigned char j=0, k=0;
  unsigned char outs[20];
  
  int table[8] = {1, 2, 4, 8, 16, 32, 64, 128};
  
  TimerInit ();
 
  DDRB = 0xF0;
  PUCR = 0X02;
  DDRP = 0X00;
  DDRT = 0XFF;


  while(1)
  {

      
      
      if(!(PTIP & 1) ){
         while(!(PTIP & 1)) {
          continue;
         }
         done = 0;
         start = 1;
         
      
      } else {
        if(!done && start) {
          PORTB = table[i];
          done = 1;
          start = 0;
          i++;
          if(i>7) i=0;
        }
      }


  }
 

  EnableInterrupts;

 
}