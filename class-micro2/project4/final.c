#include <hidef.h>      /* common defines and macros */
#include <mc9s12dt256.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dt256b"

int table[1000];
void Delay(int time);

void main(void){
 int notes[26]=   {8,0,8,0,8,0,4,0,6,0,6,0,6,0,3,0,5,0,5,0,18,0,18,0,0,0};
 int length[26]=  {1,1,1,1,1,1,4,2,1,1,1,1,1,1,4,2,1,1,1,1,1,1,1,1,4,4};
 int number=26;
 int a,b,temp;
 PTIP=0;
 PIEP_PIEP0=1;
 DDRP=0x00;
 ATD0CTL2=0x80;
 ATD0CTL4=0xE3;
 ATD0CTL5=0xA0;
 DDRB=0xFF;
   
 EnableInterrupts;
 
 for(;;){
   for(a=0;a<number;a++){
    if(length[a]==3)temp=4;
    else if(length[a]==4)temp=8;
    else temp=length[a];
    if(notes[a]==0){
      for(b=0;b<1000*temp/8;b++){
        PORTB=0;
        Delay(12);
      }
    } else{
        for(b=0;b<(1000*temp/96)*(11+notes[a])/*(1000*temp*(11+notes[a])/96)*/;b++){
         
          PORTB=table[b%1000];
          Delay(13-notes[a]);
        }
      }
     
   }
 }
}

void Delay(int time){
  int x,y=0;
  for(x=0;x<12+time;x++){
    for(y=0;y<15;y++){
      y++;y--;
    }
  }
}

void record(void){
  int x=0;
  PORTB=0xA0;
  for(x=0;x<1000;x++){
    table[x]=ATD0DR0;
    Delay(12);
  }
  PORTB=0x30;
}

#pragma CODE_SEG NON_BANKED

interrupt  void buttonpress (void) {
DisableInterrupts;
record();
PIFP_PIFP0=1;
}

#pragma CODE_SEG DEFAULT