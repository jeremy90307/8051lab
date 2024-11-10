			ORG 0
			MOV DPTR, #TABLE
START:	
			MOV R0, #0
			MOV R1, #4
			MOV R2, #11110111B
SCAN:	
			MOV A, R2
			MOV P2, A
			JNB P2.7, KEYIN
			INC R0
			JNB P2.6, KEYIN
			INC R0
			JNB P2.5, KEYIN
			INC R0
			JNB P2.4, KEYIN
			INC R0
			RR A
			MOV R2, A
			DJNZ R1, SCAN
			SJMP START
KEYIN:
			CALL DEBOUNCE
			MOV A, R0
			MOVC A, @A+DPTR
			MOV P1, A
			SJMP START
DEBOUNCE:
			MOV R4, #50
DE_500_us:
			MOV R3, #250
			DJNZ R3, $
			DJNZ R4, DE_500_us
			RET
TABLE:
			DB 10011111B	; display 1
			DB 00100101B	; display 2
			DB 00001101B	; display 3
			DB 00010001B	; display A
			DB 10011001B	; display 4
			DB 01001001B	; display 5
			DB 01000001B	; display 6
			DB 11000001B	; display b
			DB 00011011B	; display 7
			DB 00000001B	; display 8
			DB 00001001B	; display 9
			DB 11100101B	; display c
			DB 01110001B	; display F
			DB 00000011B	; display 0
			DB 01100001B	; display E
			DB 10000101B	; display d
			END