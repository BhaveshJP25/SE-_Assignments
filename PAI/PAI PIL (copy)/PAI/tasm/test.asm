.model small

.data

.code
        MOV AX,@data
        MOV dx,ax
        mov dl,67h
        mov ah,02h
        int 21h
        mov ah,4ch
        int 21h
END
