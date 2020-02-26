.model small
.data
v1 db 01h,02h,03h,04h,05h
len equ ($-v1)/2
out1 dw ?
.code
    start:
        mov ax,@data
        mov ds,ax
        lea si,v1
        clc
        xor ax,ax
        mov cx,len
    sum1:
        adc ax,[si]
        inc si
        inc si
        dec cx
        inc dx
      
        jnz sum1
        add ax,30h
        mov out1,ax
        mov dx,out1
        mov ah,02h
        int 21h
        mov ah,4ch
        int 21h
        
end start







