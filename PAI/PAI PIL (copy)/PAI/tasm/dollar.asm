.model small
.stack 100
.data
.code
main proc near
mov ax,@data
mov ds,ax
mov ah,02h
mov dl,'*'
int 21h
mov ah,4ch
int 21h
main endp
end
