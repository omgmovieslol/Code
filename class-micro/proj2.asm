; James Wilson
; @00914452
; Project #2
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
M     DS    3
N     DS    3
P     DS    6




; code section
            ORG   ROMStart
Entry:
            LDS   #RAMEnd+1       ; initialize the stack pointer
            CLI                   ; enable interrupts

;;;; /AUTO GENERATED


; declare values in table for testing
            LDD      M+1   
            LDY      N+1   
            EMUL         
            STY      P+2   
            STD      P+4   
           
           
            LDY   N+1
            LDAB  M
           
            EMUL

            STY      P   
            STD      P+2   
           
           
            LDAB     N   
            LDY      M+1

            EMUL

            ADDD    P+2   
            STD     P+2       
           
           
            TFR     y,d   
            ADCB    P
            STAB    P
            ADCA    P+1
            STAA    P+1

         
            LDAB  N
            LDAA  M
           
            MUL  
           
            ADDD  P
            STD   P  

       

;;;; ENDINGS
           
            SWI  



;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector
            END

