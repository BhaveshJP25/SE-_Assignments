.model small
.data
.code
        mov ax,@data
        mov ds,ax
        mov ah,02h
        mov dl,'A'
        int 21h
        mov ah,04ch
        int 21h
end
