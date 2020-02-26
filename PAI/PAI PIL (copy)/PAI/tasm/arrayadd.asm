.model small
.stack
.data
	output db 0h

	array db 1,2,3,4,5,6,7,8,9,10 	;Declare Array 
	len EQU ($-array) 		; Init length of array in len
	rem db 0 			; Variable for holding remainder
.code
	;INIT
	mov ax,@data
	mov ds,ax
	;end INIT
	
	
	lea SI,array	;mov offset of array into Source Index	
	xor ax,ax	;Init value of ax to 0
	mov cx,len	;Init cx by length of array
	
	;Begin Loop
sum1:	
	adc ax, [SI]	;Add with previous carry
	inc SI		;Increment the value SI
	dec cx		;Decrement Value of CX
	jnz sum1	;If counter is not zero, jump
	;End Loop	

	mov output,al	;Mov the output from AL to output variable

	mov ah,00	;Init value of ah with 0

	mov bl,10	;Mov 10 as divisor in bl
	div bl		;Perform division
	
	mov rem,ah	;Mov the remainder from ah to temporary variable rem
	mov dl,al	;MOv the value of quotient in dl for printing
	add dl,30h	;Ascii adjust for printing
	mov ah, 02h	;Int21h function for Print Character
	int 21h
	
	mov dl,rem	;Mov the remainder to dl for printing
	add dl,30h	;Ascii adjust for printing
	mov ah,02h	;Int21h function for Print Character
	int 21h		

	;Terminate Program with return code
	mov ah,4ch
	int 21h
	;END
END

Output:- 

Z:/tasm>arrayadd.exe
55