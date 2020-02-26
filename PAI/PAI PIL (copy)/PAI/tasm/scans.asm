.model small
.stack 100h
.data
        data db ?
.code
        mov ax,@data
        mov ds,ax
	mov dx,offset data
        mov ah,3fh
	add dx,30h
        int 21h
       
	
        mov ah,09h
        int 21h
	
        mov ah,4ch
        int 21h
end
