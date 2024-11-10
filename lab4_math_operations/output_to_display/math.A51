			ORG 0
			MOV DPTR, #TABLE
			MOV R5, #2		// buffer
START:	
			MOV R0, #1
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
			JNB P2.4, math_op
			RR A                                      
			MOV R2, A
			DJNZ R1, SCAN
			SJMP START
KEYIN:
			CALL DEBOUNCE
			MOV A, R0
			MOVC A, @A+DPTR
			MOV P1, A
			DJNZ R5, store
			MOV A, R0
			MOV R7, A
			SJMP START
			
store:
			MOV A, R0
			MOV R6, A			//first num
			SJMP START
math_op:	
			JNB P2.3, AD	
			JNB P2.2, SU
			JNB P2.1, MU
			JNB P2.0, DI		
			
AD:
			MOV B, R6
			MOV A, R7
			ADDC A, B
			MOV B, #0AH
			DIV AB
			SJMP lib
			
SU:
			MOV B, R6
			MOV A, R7
			SUBB A, B
			MOV B, #0AH
			DIV AB
			SJMP lib
MU:
			MOV B, R6
			MOV A, R7
			MUL AB
			MOV B, #0AH
			DIV AB
			SJMP lib
DI:
			MOV B, R6
			MOV A, R7
			DIV AB
			SJMP lib
			
lib:
			MOVC A, @A+DPTR
			MOV P1, A
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			CALL DEBOUNCE
			MOV A, B
			MOVC A, @A+DPTR
			MOV P1, A
			MOV  R0, #250
			DJNZ R0, $
			MOV R5, #2
			LJMP START
			
DEBOUNCE:
			MOV R4, #50
DE_500_us:
			MOV R3, #250
			DJNZ R3, $
			DJNZ R4, DE_500_us
			RET
TABLE:
			DB 00000011B	; display 0
			DB 10011111B	; display 1
			DB 00100101B	; display 2
			DB 00001101B	; display 3
			DB 10011001B	; display 4
			DB 01001001B	; display 5
			DB 01000001B	; display 6
			DB 00011011B	; display 7
			DB 00000001B	; display 8
			DB 00001001B	; display 9
			END