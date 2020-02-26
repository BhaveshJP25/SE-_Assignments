.model small
.stack 100h
.data
a db 03h
b db 03h
c db ?
.code 
mov ax,@data
mov ds,ax
mov al,a
;mov bl,b
add al,b
add al,30h
mov dl,al
mov ah,02h
int 21h
mov ah,4ch
int 21h
end

