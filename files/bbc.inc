		PAGE
;--------------------------------------------------------
; BBC Microcomputer Machine Operating System (MOS) Defs.
;--------------------------------------------------------
; Copyright (C),1998 Andrew John Jacobs.
; All rights reserved.
;--------------------------------------------------------

;--------------------------------------------------------
; Revision History:
;
;
;
;--------------------------------------------------------

;--------------------------------------------------------
; Operating System Vector Addresses
;--------------------------------------------------------

USERV		EQU $0200
BRKV		EQU $0202
IRQ1V		EQU $0204
IRQ2V		EQU $0206
CLIV		EQU $0208
BYTEV		EQU $020A
WORDV		EQU $020C
WRCHV		EQU $020E
RDCHV		EQU $0210
FILEV		EQU $0212
ARGSV		EQU $0214
BGETV		EQU $0216
BPUTV		EQU $0218
GPBPV		EQU $021A
FINDV		EQU $021C
FSCV		EQU $021E
EVENTV		EQU $0220
UPTV		EQU $0222
NETV		EQU $0224
VDUV		EQU $0226
KEYV		EQU $0228
INSV		EQU $022A
REMV		EQU $022C
CNPV		EQU $022E
IND1V		EQU $0230
IND2V		EQU $0232
IND3V		EQU $0234

;--------------------------------------------------------
; Operating System Entry Points
;--------------------------------------------------------

OSFIND		EQU $FFCE
OSGPBP		EQU $FFD1
OSBPUT		EQU $FFD4
OSBGET		EQU $FFD7
OSARGS  	EQU $FFDA
OSFILE		EQU $FFDD 
OSRDCH		EQU $FFE0
OSASCI		EQU $FFE3
OSNEWL		EQU $FFE7
OSWRCH		EQU $FFEE
OSBYTE		EQU $FFF1
OSWORD		EQU $FFF4
OSCLI		EQU $FFF7

