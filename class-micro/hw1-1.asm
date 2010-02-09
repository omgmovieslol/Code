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
TABLE:      DS    20
TABLE2:     DS    20
SIZE:       EQU   20
TTMP1:      DS    1
TTMP2:      DS    1


; code section
            ORG   ROMStart
Entry:
            LDS   #RAMEnd+1       ; initialize the stack pointer
            CLI                   ; enable interrupts

;;;; /AUTO GENERATED


; declare values in table for testing

            LDX   #TABLE
            CLRA
            LDAB  #SIZE
LOOPZ:
            INCA
            STAA  1,X+
            DBNE  B,LOOPZ
            
            


; problem 1
; copy table to table2

            LDX   #TABLE2
            LDY   #TABLE
            LDAB  #SIZE
            CLRA
            
LOOP:
            LDAA   1,Y+
            STAA  1,X+
            DBNE  B,LOOP


; problem 2
; swap values between table and table2


            LDX   #TABLE
            LDY   #TABLE2
            
            LDAB   #SIZE


LOOP2:
            
            
            LDAA  0,X
            STAA  TTMP1
            LDAA  0,Y
            STAA  1,X+
            LDAA  TTMP1
            STAA  1,Y+
            
            
            
            DBNE  B,LOOP2 

            
; problem 3
; reverse data in table 1 and put it in table 2
          
            LDX   #TABLE+SIZE-1
            LDY   #TABLE2
            LDAB  #SIZE
           
LOOP3:
            LDAA  1,X-
            STAA  1,Y+
            
            DBNE  B,LOOP3
          



; problem 4
; find the smallest value in table
; TTMP2 stores the smallest value at the end
            
            LDX   #TABLE
            LDY   #SIZE
            LDAB 0,X
            
LOOP4:
            ;LDAA  0,X
            CMPB  X
            BGT   LTB
            BLT   GOOD
            BEQ   GOOD

LTB:
            LDAB  0,X

GOOD:             
            LDAA  1,X+
            
            
            DBNE  Y,LOOP4
            
            STAB  TTMP2



;;;; ENDINGS
            
            SWI   



;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector
            END


