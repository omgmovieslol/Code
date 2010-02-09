;*****************************************************************
;* James Wilson
;* @00914452
;* Project 4 / Homework
;*****************************************************************

; export symbols
            XDEF Entry            ; export 'Entry' symbol
            ABSENTRY Entry        ; for absolute assembly: mark this as application entry point

; include derivative specific macros
            INCLUDE 'MC9S12KT256.inc'

ROMStart    EQU  $4000  ; absolute address to place my code/constant data

; variable/data section

            ORG RAMStart
 ; Insert here your data definition.
TBL1      DS  5
TBL2      DS  5
TBL3      DS  10
TLV1      EQU 2
TLV2      EQU 4
TLV3      EQU 6
LENG      EQU 5


; code section
            ORG   ROMStart
Entry:
            LDS   #RAMEnd+1       ; initialize the stack pointer
            CLI                   ; enable interrupts


            LDY   LENG
         

            LEAS  -6,SP
           
           
            LDD   #TBL3
            PSHD
           
           
            LDD   #TBL2
            PSHD
           
            LDD   #TBL1
            PSHD
           
           
            BSR MULTI
           
           
           
            SWI
           
           
MULTI:
           
            LDX TLV1,SP
           
           
            LDAA  1,X+
           
            STX TLV1,SP
           
            LDX TLV2,SP
           
            LDAB  1,X+
           
            MUL
           
           
            STX TLV2,SP
           
            LDX TLV3,SP
           
            STD 1,X+
           
            INX
           
            STX TLV3,SP
           
           
            DBNE Y, MULTI
           
           
            RTS



;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector
