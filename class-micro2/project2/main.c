#include <hidef.h>      /* common defines and macros */
#include <mc9s12dt256.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dt256b"


#define AMOUNT 20


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

void flash(void) {
  char i;
  for(i=0; i<10; i++) {
    PORTB = 0x10;
    PORTB = 0X20;
    PORTB = 0X40;
    PORTB = 0X80;
  }
}

//void save(int val[], int i) {
//  val[i] = PORTB << 4;
//}
  


void main(void) {

  char i, cntas, temp, b1;
  char vals[20];
  int check;
  
  PUCR = 0X02;
  DDRB = 0XF0;
  DDRP = 0X00;
  
  TimerInit ();
  
  cntas = AMOUNT;
 
  b1 = PTIP;
  
  //for(i = 0; i < AMOUNT; i++) {
       while(PTIP == 0xCC) {
      //while(1){
          temp = PORTB;
          temp = temp << 4;
          //PORTB = temp;
          
          b1 = PTIP == 0xCC;
          PORTB = b1 << 4;
          
          //b1 = PTIP << 7;
          //b1 = b1 >> 7;
          
          //PORTB = b1 << 4;
          
          //flash();
          
          
      }
      
      //save(vals,i);
      //mswait(500);
  //}
  
}
     