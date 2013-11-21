display macro arg
	lea dx,arg
	mov ah,09h
	int 21h
endm
read  macro
	display str1
	mov ah,01h
	int 21h
	sub al,30h
	mov bl,0ah
	mul bl
	push ax
	mov ah,01h
	int 21h
	sub al,30h
	mov ah,00h
	pop bx
	add ax,bx
	mov a,ax
endm
datas segment
	a dw ?
	res dw ?
menu db 0ah,0dh,"1.ADD    2.SUB  3.MUL   4.DIV 5.EXIT$"
choice db 0ah,0dh,"Enter your choice$"
str1 db 0ah,0dh,"Enter no:$"
str2 db 0ah,0dh,"RESULT IS $"
str3 db 0ah,0dh,"RESULT IS -$"
str4 db 0ah,0dh,"quotient is 0 & remainder is $"
str5 db 0ah,0dh,"quotient is $"
str6 db 0ah,0dh,"remainder is $"
datas ends
assume ds:datas,cs:codes
codes segment
start:	mov ax,datas
	mov ds,ax
loo:		display menu
		display choice
		mov ah,01h
		int 21h
		cmp al,31h
		jnz subs
		read
		mov cx,a
		read
		add cx,ax
		mov res,cx
		display str2
		call ndisp
ndisp proc
	mov cx,0000h
	mov ax,res
	mov bx,0ah
	l1:	mov dx,0000h
		div bx
		push dx
		inc cx
		cmp ax,0000h
		jnz l1
	l2:	pop dx
		add dx,30h
		mov ah,02h
		int 21h
		loop l2
ndisp endp
		jmp loo
subs:		cmp al,32h
		jnz mult
		read
		mov cx,a
		read
		cmp cx,a
		jl l3
		sub cx,a
		mov res,cx
		display str2
		call ndisp
		jmp loo
l3:		sub a,cx
		mov cx,a
		mov res,cx
		display str3
		call ndisp
		jmp loo
mult:		cmp al,33h
		jnz divi
		read
		push a
		read
		mov bx,a
		pop ax
		mul bx
		mov res,ax
		display str2
		call ndisp
		jmp loo
divi:		cmp al,34h		
		jnz last
		read
		push a
		read
		mov cx,a
		pop ax
		cmp ax,cx
		jl l4
		jmp l5
last:		mov ah,4ch
		int 21h		
l4:		mov dx,0000h
		div cx
		mov res,dx
		display str4
		call ndisp
		jmp loo
l5:		mov dx,0000h
		div cx
		mov a,ax
		push dx
		display str5
		mov cx,0000h
		mov bx,0ah
		l6:	mov dx,0000h
			mov ax,a
			div bx
			push dx
			inc cx
			cmp ax,0000h
			jnz l6
		l7:	pop dx
			add dx,30h
			mov ah,02h
			int 21h
			loop l7
		mov dx,00h	
		pop dx
		mov res,dx
		display str6
		call ndisp
		jmp loo

codes ends
end start
