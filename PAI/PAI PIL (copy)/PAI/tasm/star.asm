.model small
.data

.code
        mov ax,@data
        mov ds,ax

        mov ah,02h
        mov dl,2AH
        int 21h
        mov ah,4ch
        int 21h
END
