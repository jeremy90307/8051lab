			ORG 00H
			SJMP MAIN
			ORG 03H
			SJMP INT0_ISR
			ORG 013H
			SJMP INT1_ISR
			ORG 030H
MAIN:
			MOV IE,#10000101B	; enable EA and EX0 and EX1
			MOV SP, #30H		; stack start from #30H
			CLR IT0			; low level-triggered
			CLR IT1			; low level-triggered
			SETB IP.2
			MOV A, #00000000B
LOOP:
			MOV P2,A			; LED output
			CALL DELAY
			CPL A				; reverse A
			SJMP LOOP
INT0_ISR:
			PUSH PSW			; push PSW into stack
			PUSH ACC			; push ACC into stack
			CLR RS1
			SETB RS0			; switch to RB1
			MOV A, #11110000B
			MOV R0,#25			; loop counter -> 3
ROTATE_1:
			MOV P2,A
			CALL DELAY
			RL A
			DJNZ R0,ROTATE_1
			POP ACC
			POP PSW
			RETI				; return from ISR
INT1_ISR:
			PUSH PSW
			PUSH ACC
			CLR RS0
			SETB RS1			; switch to RB2
			MOV A, #11111110B
			MOV R0, #17			; loop counter -> 2
ROTATE_2:
			MOV P2,A
			CALL DELAY
			RL A
			DJNZ R0,ROTATE_2
			POP ACC
			POP PSW
			RETI				; return from ISR	
DELAY:
			MOV R7, #200
DE_500_us:
			MOV R6, #250
			DJNZ R6, $
			DJNZ R7, DE_500_us
			RET
			END