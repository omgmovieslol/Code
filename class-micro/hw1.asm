; James Wilson
; @00914452
; Homework #1
;
;


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
;;;; DECLARATIONS

MUTA:       DS    4
MUTB:       DS    4
MUTC:       DS    8
MUTT:       EQU   4

TMPA:       DS    2
TMPB:       DS    2
TMPC:       DS    2
TMPT:       DS    2

VALS:       DS    1
TABLE:      DS    20
SIZE:       EQU   20
LRG1:       DS    1
LRG2:       DS    1




; code section
            ORG   ROMStart
Entry:
            LDS   #RAMEnd+1       ; initialize the stack pointer
            CLI                   ; enable interrupts

;;;; /AUTO GENERATED


; declare values in table for testing

            LDX   #TABLE
            STX   TMPA
            CLRA
            LDAB  #SIZE
LOOPZ:
            INCA
            STAA  1,X+
            DBNE  B,LOOPZ


            LDX   #MUTA
            CLRA
            LDAB  #4
LOOPZ1:
            INCA
            STAA  1,X+
            DBNE  B,LOOPZ1
           


            LDX   #MUTB
            CLRA
            LDAB  #4
LOOPZ2:
            INCA
            STAA  1,X+
            DBNE  B,LOOPZ2
           
           


; problem 1
; copy table to table2

;            LDX   #TABLE2
;           LDY   #TABLE
;            LDAB  #SIZE
;            CLRA
;           
;LOOP:
;            LDAA   1,Y+
;            STAA  1,X+
;            DBNE  B,LOOP


; problem 2
; swap values between table and table2


;            LDX   #TABLE
;            LDY   #TABLE2
;           
;            LDAB   #SIZE
;
;
;LOOP2:
;           
;           
;            LDAA  0,X
;            STAA  TTMP1
;            LDAA  0,Y
;            STAA  1,X+
;            LDAA  TTMP1
;            STAA  1,Y+
;           
;           
;           
;            DBNE  B,LOOP2

           
; problem 3
; reverse data in table 1 and put it in table 2
         
;            LDX   #TABLE+SIZE-1
;            LDY   #TABLE2
;            LDAB  #SIZE
;          
;LOOP3:
;            LDAA  1,X-
;            STAA  1,Y+
;           
;            DBNE  B,LOOP3
         



; problem 4
; find the smallest value in table
; TTMP2 stores the smallest value at the end
           
;            LDX   #TABLE
;            LDY   #SIZE
;            LDAB 0,X
;           
;LOOP4:
;            ;LDAA  0,X
;            CMPB  X
;            BGT   LTB
;            BLT   GOOD
;            BEQ   GOOD
;
;LTB:
;            LDAB  0,X
;
;GOOD:            
;            LDAA  1,X+
;           
;           
;            DBNE  Y,LOOP4
;           
;            STAB  TTMP2
;

; problem 1
; number of bits equal to 1 in $1000-1

;           LDAA  #$1000
;           LDX   #8
;           LDY   #0
;LOOPB1:
;           BITA  X
;

;INCRE:

; problem 2
; 32 bit * 32 bit => 64 bit
                       

            LDX   #MUTA
            STX   TMPA
            LDX   #MUTB
            STX   TMPB
            LDX   #MUTC
            STX   TMPC
            LDY   #4
            STY   TMPT          
LOOPB2:
            STY   TMPT
           
            LDX   TMPA
            LDY   TMPB
           
            LDAA  1,X+
           
            ;INX
            ;INX
            ;INX
            ;INX
           
            LDAB  1,Y+
           
            STX   TMPA
            STY   TMPB
           
            LDX   TMPC
           
            MUL
           
            ;INX
            ;INX
            ;INX
            ;INX
           
            STD   2,X+
           
           
            STX   TMPC
           
            LDY   TMPT
           
            DBNE  Y,LOOPB2


; problem 3
; find 2 largest
; LRG1 contains largest
; LRG2 contains 2nd largest
           
            LDX   #TABLE
            LDY   #SIZE
            LDAA  #0
            STAA  LRG1
            STAA  LRG2
            LDAB 0,X
           
LOOP4:
            ;LDAA  0,X
            CMPB  X
            BLT   LTB
            BGT   GOOD
            BEQ   GOOD

LTB:
            STAB  LRG2
            LDAB  0,X
           
           

GOOD:            
            LDAA  1,X+
           
           
            DBNE  Y,LOOP4
           
            STAB  LRG1


;;;; ENDINGS
           
            SWI  



;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector
            END

