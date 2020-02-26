.model small
.data
	A db 3h
	B db 2h
	C dw ?
.code
	mov ax,@data
	mov ds,ax
	mov al,A
	ADD al,B
	ADD AL,30H
	mov C, AX
	mov DX, AX
	mov ah,02h
	int 21h

	mov ah, 4ch
	int 21h
END	