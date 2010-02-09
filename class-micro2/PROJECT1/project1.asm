;*****************************************************************
;* This stationery serves as the framework for a                 *
;* user application (single file, absolute assembly application) *
;* For a more comprehensive program that                         *
;* demonstrates the more advanced functionality of this          *
;* processor, please see the demonstration applications          *
;* located in the examples subdirectory of the                   *
;* Freescale CodeWarrior for the HC12 Program directory          *
;*****************************************************************

; export symbols
            XDEF Entry            ; export 'Entry' symbol
            ABSENTRY Entry        ; for absolute assembly: mark this as application entry point

; include derivative specific macros
            INCLUDE 'mc9s12dt256.inc'

ROMStart    EQU  $4000  ; absolute address to place my code/constant data

; variable/data section

            ORG RAMStart
 ; Insert here your data definition.
STORED      DS 10


; code section
            ORG   ROMStart
Entry:
            LDS   #RAMEnd+1       ; initialize the stack pointer
            ;CLI                   ; enable interrupts
mainLoop:
            LDAA #$02
            STAA PUCR
          
            CLRA
            STAA PTIP
            LDAA #$F0
            STAA DDRB
            CLRA
            ;STAA DDRP
            
            MOVB #0, DDRP
            
            LDY #10
            LDX #STORED
            
Loop:
            LDAA PORTB
            LSLA
            LSLA
            LSLA
            LSLA
            
            ROLA
            RORB
            ROLA
            RORB
            ROLA
            RORB
            ROLA
            RORB
            
            
            
                     
            ;BSR DELAY
            STAB PORTB
            LDAA PTP
            ANDA  #1
            BNE NEXT
            
            
            STAB 1,X+
            
            
            
            BSR DELAY
            DBNE Y,Loop
            
            BRA OUTPUT
            
NEXT:
            BRA Loop         
           
DELAY:
            PSHD
            PSHX
            PSHY
            LDAB #5
OLOOP:
            LDX #20000
ILOOP:
            PSHA
            PSHA
            PSHA
            PSHA
            PSHA
            PSHA
           
            PULA
            PULA
            PULA
            PULA
            PULA
            PULA
           
            NOP
            NOP
            DBNE X, ILOOP
           
            DBNE B, OLOOP
            PULY
            PULX
            PULD
            RTS

            
            
OUTPUT:
            
            LDX #STORED
            LDY #10
            
OUTLOOP:
            
            LDAA 1,X+
            
            STAA PORTB
            
            BSR DELAY
            
            DBNE Y, OUTLOOP
            
            
            SWI
            
           


;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector
            END