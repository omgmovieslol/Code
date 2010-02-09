; ************************************
; James Wilson
; @00914452
; Homework #2
;
; ************************************


;;;; AUTO GENERATED
; export symbols
            XDEF Entry            ; export 'Entry' symbol
            ABSENTRY Entry        ; for absolute assembly: mark this as application entry point

; include derivative specific macros
            INCLUDE 'MC9S12KT256.inc'

ROMStart    EQU  $4000  ; absolute address to place my code/constant data

; variable/data section

            ORG RAMStart
; Insert here your data definition.
            ORG $1100
;;;; DECLARATIONS
M:          DS    4
N:          DS    4
P:          DS    8
MUTT:       EQU   4

TMPA:       DS    2
TMPB:       DS    2
TMPC:       DS    2
TMPT:       DS    2


TABLE:      DS    20
SIZE:       EQU   20
LRG1:       DS    1
LRG2:       DS    1

COUNT:      DS    1

LPCNT:      DS    1
ZERCT:      DS    1




; code section
            ORG   ROMStart
Entry:
            LDS   #RAMEnd+1       ; initialize the stack pointer
            CLI                   ; enable interrupts

;;;; /AUTO GENERATED


; declare values in table for testing

;            LDX   #TABLE
;            STX   TMPA
;            CLRA
;            LDAB  #SIZE
;LOOPZ:
;            INCA
;            STAA  1,X+
;            DBNE  B,LOOPZ
;
;
;            LDX   #M
;            CLRA
;            LDAB  #4
;LOOPZ1:
;            INCA
;            STAA  1,X+
;            DBNE  B,LOOPZ1
;          
;
;
;            LDX   #N
;            CLRA
;            LDAB  #4
;LOOPZ2:
;            INCA
;            STAA  1,X+
;            DBNE  B,LOOPZ2
          
          


; problem 1
; number of bits equal to 1 in $1000-1

           CLR    ZERCT
           LDAA   #16
           STAA   LPCNT
           LDD  $1000
LOOPB1:
           ASLD
           BCC   SKIP


           INC    ZERCT
        
SKIP:
           DEC    LPCNT
           BNE   LOOPB1
          
          
        
          




; problem 2
; 32 bit * 32 bit => 64 bit
                      

            ldd    M+2   
              ldy    N+2   
              emul        
              sty    P+4   
              std    P+6   
              ldd    M   
              ldy    N
                 
              emul
                     
              sty    P   
              std    P+2   
              ldd    M   
              ldy    N+2
                 
              emul
                     
              addd    P+4   
              std    P+4       
              tfr    y,d   
              adcb    P+3
              stab    P+3
              adca    P+2
              staa    P+2

              ldaa    P+1
              adca    #0   
              staa    P+1   
              ldaa    P
              adca    #0   
              staa    P

              ldd    M+2   
              ldy    N
                 
              emul       

              addd    P+4   
              std    P+4   
              tfr    y,d   
              adcb    P+3
              stab    P+3
              adca    P+2
              staa    P+2

              ldaa    P+1
              adca    #0   
              staa    P+1
              ldaa    P
              adca    #0   
              staa    P



; problem 3
; find 2 largest
; LRG1 contains largest
; LRG2 contains 2nd largest


; this does work
; it's super hacks
; largest 2 /unique/ integers
; first loop fails if the first is the largest
; second loop fails if last and first are the max
; comparison at the end to fix second loop fail
          
            LDX   #TABLE
            LDY   #SIZE
            LDAA  #0
            STAA  LRG1
            STAA  LRG2
            LDAB  #-128
          
LOOP4:

            CMPB  X
            BGE   GOOD

            STAB  LRG2
            LDAB  0,X
          

GOOD:           
            INX
          
          
            DBNE  Y,LOOP4
           
           
            STAB  LRG1
           

            LDX   #TABLE+19
            LDY   #SIZE
            LDAB  X
            CMPB  LRG1
            BNE   LOOP41
            DEX  
            LDAB  X
          
LOOP41:

            CMPB  X
            BGE   GOOD1

            STAB  LRG2
            LDAB  0,X
          

GOOD1:           
            DEX
          
          
            DBNE  Y,LOOP41

          
            CMPB  LRG1
           
            BLT   BAD
          
            STAB  LRG1
            BRA   FIN
           
      
BAD:
            STAB  LRG2
          
FIN:

           

;;;; ENDINGS
          
            SWI 



;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector
            END

