		PAGE
;--------------------------------------------------------
; Debugging Utility Functions
;--------------------------------------------------------
; Copyright (C),1999 Andrew John Jacobs
; All rights reserved.
;--------------------------------------------------------

; Prints the address of the next instruction to be
; executed, the processor status flags and the values in
; all the registers.

DUMP_REGISTERS	PHP		;Push everything
		PHA
		TXA
		PHA
		TYA
		PHA

		TSX		;Get stack top
				
		LDA #'P'	;Dump PC
		JSR OSWRCH
		LDA #'C'
		JSR OSWRCH
		JSR DUMP_EQUALS
		LDA $0105,X
		LDY $0106,X	
		CLC		;Correct return
		ADC #1		; address
		BCC *+3
		INY
		JSR DUMP_WORD

		JSR DUMP_SPACE	;Dump status flags
		LDY #0
		LDA $0104,X
DUMP_STATUS	ROL A
		PHA
		LDA DUMP_BITS,Y
		BCS *+4
		LDA #'.'
		JSR OSWRCH
		PLA
		INY
		CPY #8
		BNE DUMP_STATUS
				
		JSR DUMP_SPACE	;Dump A	
		LDA #'A'
		JSR OSWRCH
		JSR DUMP_EQUALS
		LDA $0103,X
		JSR DUMP_BYTE
		
		JSR DUMP_SPACE	;Dump X
		LDA #'X'
		JSR OSWRCH
		JSR DUMP_EQUALS
		LDA $0102,X
		JSR DUMP_BYTE
		
		JSR DUMP_SPACE	;Dump Y
		LDA #'Y'
		JSR OSWRCH
		JSR DUMP_EQUALS
		LDA $0101,X
		JSR DUMP_BYTE

		JSR DUMP_SPACE	;Dump S
		LDA #'S'
		JSR OSWRCH
		JSR DUMP_EQUALS
		CLC
		TXA
		ADC #6
		JSR DUMP_BYTE

		JSR OSNEWL		
		
		PLA		;Restore everything
		TAY
		PLA
		TAX
		PLA
		PLP
		RTS

; Symbolic codes for status register bits

DUMP_BITS	DB  'NV.BDIZC'

; Prints a 16 bit word held in A (LO) &amp; Y (HI) on the
; screen in hexadecimal.
;
; A is are destroyed. X and Y are preserved.
		
DUMP_WORD	PHA
		TYA
		JSR DUMP_BYTE
		PLA

; Prints an 8 bit byte held in A on the screen in
; hexadecimal.
;
; A is destroyed. X and Y are preserved.

DUMP_BYTE	PHA
		LSR A
		LSR A
		LSR A
		LSR A
		JSR DUMP_NYBBLE
		PLA
		AND #$0F

; Converts the 4 bit nybble in A to an ASCII character
; representing its hexadecimal value and prints it.
;
; A is destroyed. X and Y are preserved.

DUMP_NYBBLE	ORA #'0'
		CMP #'9'+1
		BCC *+4
		ADC #6
		JMP OSWRCH

; Utility routines to print space and equals characters.
;
; A is destroyed. X and Y are preserved.

DUMP_SPACE	LDA #' '
		BNE *+4
DUMP_EQUALS	LDA #'='
		JMP OSWRCH

