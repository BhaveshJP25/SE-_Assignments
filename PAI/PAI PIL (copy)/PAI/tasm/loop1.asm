.model small

.data
	stri db 10 DUP('$')

.stack 100h

.code
	mov dx,@data
	mov ds,dx
	lea dx,stri
	mov ah,3fh
	int 21h

	mov cx,0h
	mov ah,09h

loop1:	
	int 21h
	inc cx
	cmp cx,10h
	jne loop1
	mov ah,4ch
	int 21h
END