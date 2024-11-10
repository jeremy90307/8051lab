			ORG 00H
			SJMP MAIN
			ORG 03H
			SJMP INT0_ISR
			ORG 030H
MAIN:
			MOV IE,#10000001B	; enable EA and EX0
			MOV SP, #30H		; stack start from #30H
			SETB IT0			; falling edge-triggered
			MOV A, #00000000B	
LOOP:
			MOV P2,A			; LED output
			CALL DELAY
			CPL A
			SJMP LOOP
INT0_ISR:
			PUSH PSW			; push PSW into stack
			PUSH ACC			; push ACC into stack
			SETB RS0			; switch to RB1
			MOV A, #11111110B
			MOV R0,#24			; loop counter -> 24
ROTATE_L:
			MOV P2,A
			CALL DELAY
			RL A
			DJNZ R0,ROTATE_L
			POP ACC
			POP PSW
			RETI				; return from ISR
DELAY:
			MOV R7, #250
DE_500_us:
			MOV R6, #250
			DJNZ R6, $
			DJNZ R7, DE_500_us
			RET
			END