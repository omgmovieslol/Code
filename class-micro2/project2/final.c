#include <hidef.h>      /* common defines and macros */
#include <mc9s12dt256.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dt256b"


#define AMOUNT 4


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

void flash(void) { // NIGHTRIDER
  PORTB = 0xEE;
   mswait(150);
   PORTB = 0XDD;
   mswait(150);
   PORTB = 0XBB;
   mswait(150);
   PORTB = 0X77;
   mswait(150);
   PORTB = 0XBB;
   mswait(150);
   PORTB = 0XDD;
   mswait(150);
   PORTB = 0xEE;
   mswait(150);
   PORTB = 0XDD;
   mswait(150);
   PORTB = 0XBB;
   mswait(150);
   PORTB = 0X77;
   mswait(150);
   PORTB = 0XBB;
   mswait(150);
   PORTB = 0XDD;
   mswait(150);
}

  


void main(void) {

  char i, cntas, temp, b1;//, small, great;
  unsigned int vals[AMOUNT];
  int check;
  unsigned int great, small;
  
  PUCR = 0X02;
  DDRB = 0XF0;
  DDRP = 0X00;
  
  TimerInit ();
  //while(1) // uncomment for awesomeness
  flash();
  
  cntas = AMOUNT;
 
  b1 = PTIP;
  
  for(i = 0; i < AMOUNT; i++) {
       while((PTIP & 1)) {
          temp = PORTB;
          temp = temp << 4;
          PORTB = temp;
          
       }
       
       vals[i] = PORTB;// >> 4;
       
       
       flash();
            
  }
  
  
  
  great = vals[0];
  small = vals[0];
  
  for(i=0; i<AMOUNT; i++){
    if(vals[i] > great){
      great = vals[i];
    }
    if(vals[i] < small) {
      small = vals[i];
    }
  }
  
  PORTB = great;// << 4;
  mswait(1000);
  flash();
  
  PORTB = small;// << 4;
  mswait(1000);
  flash();
  
  for(i = AMOUNT - 1; i >= 0; i--) {
    PORTB = vals[i];
    mswait(500);
  }
  
}
     