.model small

.data
	num db 10h
	deci db 10 DUP(0)

.stack

.code
	;Init
	mov dx,@data
	mov ds,dx
	;End Init
	
	mov cx,0h
	mov al,num
	mov bl,10
loop1:	
	
	div bl
	inc cx
	cmp al,0
	jnz loop1
	
	lea di, deci
	add di, cx
	mov bl,16
loop2:	mov al,num
	div bl
	mov [di],ah
	dec di
	dec cx
	jnz loop2
	
	mov dl,deci
	mov ah,02h
	int 21h
	mov ah,4ch
	int 21h
END
	
		
	
	