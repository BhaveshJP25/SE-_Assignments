.model small
.data
        var db "hello$"
.code
        mov ax,@data
        mov ds,ax
        mov dx,offset var
        mov ah,09h
        int 21h
        mov ah,04ch
        int 21h
end
