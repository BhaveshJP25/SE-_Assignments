.model small

.stack

.data
      
	str1 db 255 DUP('$')
.code
        mov ax,@data
        mov ds,ax
	lea si,str1
        mov ah,01h
        
READ:
	int 21h
	mov [si],AL
		
	INC SI
	CMP AL,13 ;carriage return
	jne READ
	
	


        mov dl,str1
        mov ah,09h
        int 21h

        mov ah,4ch
        int 21h
END

