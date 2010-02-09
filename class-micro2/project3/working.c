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
 
  //float temp, volts, resistance;

  //int table [255] = { 440 , 372 , 336 , 312 , 295 , 281 , 269 , 260 , 251 , 244 , 237 , 231 , 226 , 221 , 216 , 212 , 208 , 205 , 201 , 198 , 195 , 192 , 189 , 186 , 184 , 181 , 179 , 177 , 174 , 172 , 170 , 168 , 166 , 164 , 163 , 161 , 159 , 158 , 156 , 154 , 153 , 151 , 150 , 148 , 147 , 146 , 144 , 143 , 142 , 141 , 139 , 138 , 137 , 136 , 135 , 133 , 132 , 131 , 130 , 129 , 128 , 127 , 126 , 125 , 124 , 123 , 122 , 121 , 120 , 119 , 118 , 117 , 116 , 116 , 115 , 114 , 113 , 112 , 111 , 110 , 110 , 109 , 108 , 107 , 106 , 106 , 105 , 104 , 103 , 102 , 102 , 101 , 100 , 99 , 99 , 98 , 97 , 97 , 96 , 95 , 94 , 94 , 93 , 92 , 92 , 91 , 90 , 89 , 89 , 88 , 87 , 87 , 86 , 85 , 85 , 84 , 83 , 83 , 82 , 81 , 81 , 80 , 79 , 79 , 78 , 77 , 77 , 76 , 76 , 75 , 74 , 74 , 73 , 72 , 72 , 71 , 70 , 70 , 69 , 69 , 68 , 67 , 67 , 66 , 65 , 65 , 64 , 63 , 63 , 62 , 62 , 61 , 60 , 60 , 59 , 58 , 58 , 57 , 56 , 56 , 55 , 54 , 54 , 53 , 53 , 52 , 51 , 51 , 50 , 49 , 49 , 48 , 47 , 47 , 46 , 45 , 45 , 44 , 43 , 42 , 42 , 41 , 40 , 40 , 39 , 38 , 38 , 37 , 36 , 35 , 35 , 34 , 33 , 32 , 32 , 31 , 30 , 29 , 28 , 28 , 27 , 26 , 25 , 24 , 23 , 23 , 22 , 21 , 20 , 19 , 18 , 17 , 16 , 15 , 14 , 13 , 12 , 11 , 10 , 9 , 8 , 7 , 6 , 5 , 3 , 2 , 1 , 0 , -1 , -2 , -3 , -5 , -6 , -8 , -10 , -11 , -13 , -15 , -17 , -19 , -21 , -23 , -26 , -28 , -31 , -34 , -38 , -41 , -45 , -50 , -56 , -64 , -73 , -89 };
 
  DDRB = 0xF0;
  PUCR = 0X02;
  DDRP = 0X00;
  ATD0CTL2 = 0X80;
  ATD0CTL3 = 0X06;
  ATD0CTL4 = 0X83;
  ATD0CTL5 = 0XA0;
  ATD0DIEN = 0X01;

/*
  b = PORTAD0_PTAD0;
  printf("PORTAD0_PTAD0 = %s",PORTAD0_PTAD0);
*/


  while(1)
  {
    i++;
    if(i > 19)
      i=0; 
   
    b = PORTAD0_PTAD0;
    a = ATD0DR0;
   
   
    //volts = a / 51.0;
    //resistance = ( (volts/5.0)*10000)/(1 + volts/5.0);
    //temp = 1/( A1 + B1 * log(resistance/Rref) + C1 * log(resistance/Rref) * log(resistance/Rref) + D1 * log(resistance/Rref) * log(resistance/Rref) * log(resistance/Rref));
    //table[i] = (short) temp;
   
    outs[i] = table[a/5];
   
    for(j=0; j<5; j++) {
      PORTB = j << 4;
      mswait(500);
      if(!(PTIP & 1) ){

        for(k=i-5;k<i;k++){
          PORTB = outs[k];
          mswait(2000);
          PORTB = outs[k] << 4;
          mswait(2000);
        }
      }
    }
    // OUTPUT CURRENT VALUE
    //PORTB = outs[i];
    //mswait(1000);
    //PORTB = outs[i] << 4;
    //mswait(1000);
   
    //mswait(5000);


  }
 

  EnableInterrupts;

 
}