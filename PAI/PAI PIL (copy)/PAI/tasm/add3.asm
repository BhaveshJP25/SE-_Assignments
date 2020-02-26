.model small
.data
        a db 3h
        b db 2h
        c db ?
.code
        mov ax,@data
        mov ds,ax
        mov al,a
        mov bl,b
        add al,bl
        
        add al,30h
        mov c,al
        mov dl,al
        mov ah,02h
        int 21h
        mov ah,4ch
        int 21h
end
