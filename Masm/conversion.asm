display macro arg
	lea dx,arg
	mov ah,09h
	 int 21h
endm
read macro
	mov ah,01h
	int 21h
endm
data segment
	res dw 0
	msg1 db 0ah,0dh,"1.binary to decimal 2.Hexadecimal to decimal 3.exit$"
	msg2 db 0ah,0dh,"Enter your choice $"
	str1 db 0ah,0dh,"Enter the 8 bit binary no: $"
	str2 db 0ah,0dh,"Decimal representation is $"
	get db 0ah,0dh,"Enter the hexadecimal no: $"
data ends
code segment 
	assume cs:code,ds:data
start:	mov ax,data
	mov ds,ax
	
loo:	display msg1
	display msg2
	mov ah,01h
	int 21h
	cmp al,31h
	jnz l	
	mov cx,8h
	display str1
	mov bx,0h
	l1:	mov ax,0h
		mov  ah,01h
		int 21h
		sub ax,30h
		mov ah,0h
		or bx,ax
		shl bx,1
		loop l1
		shr bx,1
		mov ax,00h
		display str2
	mov ax,bx
	call prints
prints proc
	mov cx,00h
	mov dx,00h
	mov bl,0ah
	l4:
		div bl
		mov dx,ax
		mov dl,00h
		push dx
		inc cx
		mov ah,00h
		cmp al,00h
		jnz l4
	l5:
		pop dx
		mov dl,dh
		mov dh,00h
		add dx,30h
		mov ah,02h
		int 21h
		loop l5
mov dx,00h
prints endp
	jmp loo
l:	cmp al,32h
	jnz exit2
	mov bx,0
	display get
l3:	read
	mov ah,00h
	cmp ax,0dh
	jz done
	cmp ax,39h
	jg alpha
	sub ax,30h
	jmp makenum
alpha:		sub ax,57h
makenum:	shl bx,1
		shl bx,1
		shl bx,1
		shl bx,1
		or bx,ax
		jmp l3
done:	mov res,bx
	call dispnum
dispnum proc
	display str2
	mov cx,00h
	mov ax,res
	mov bx,0ah
l7:	mov dx,00h
	div bx
	push dx
	inc cx
	cmp ax,00h
	jnz l7
l8:	pop dx
	add dx,30h
	mov ah,02h
	int 21h
	loop l8
	jmp loo
dispnum endp
exit2:	mov ah,4ch
	int 21h

code ends
end start
