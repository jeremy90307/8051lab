	ORG 00H
	MOV A, #11111110B 

LOOP: 
	MOV P1, A
	CALL DELAY
	RL A
	SJMP LOOP

DELAY:
	MOV R0, #4

LOOP1:
	MOV R1, #250

LOOP2:
	MOV R2, #250
	DJNZ R2, $
	DJNZ R1, LOOP2
	DJNZ R0, LOOP1
	RET
	
	END