print macro msg
mov dx,offset msg
mov ah,09h
int 21h
endm

data segment
c1 dw 0
c2 dw 0
str1 db 0ah,0dh,"enter string :$"
str2 db 0ah,0dh,"number of vowels :$"
str3 db 0ah,0dh,"number of consonents :$"
str5 db 20 dup(?)
data ends

code segment
assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	print str1
	mox cx,00
	mov si,offset str5
a1:	mov ah,01h
	int 21h
	cmp al,13
	jz a2
	mov [si],al
	inc si
	inc cx
	jmp al
a2:	mov bl,'$'
	mov [si],bl
	mov si,offset str5
aa:	mov al,[si]
	cmp al,'a'
	jne a3
	jmp jj
a3:	cmp al,'e'
	jne a4
	jmp jj
a4:	cmp al,'i'
	jne a5
	jmp jj
a5:	cmp al,'o'
	jne a6
	jmp jj
a6:	cmp al,'u'
	jne a7
	jmp jj
a7:	cmp al,' '
	je a8
	add c2,01
	jmp a8
jj:	add c1,01
a8:	inc si
	loop aa
	print str2
	mov ax,c1
	call ndisp
	print str3
	mov ax,c2
	call ndisp
	jmp exit
	ndisp proc
	mov cx,00h
	mov bx,0ah
l6:	mov dx,00h
	div bx
	push dx
	inc cx
	cmp ax,00h
	jnz l6
l7:	pop dx
	add dx,30h
	mov ah,02h
	int 21h
	loop l7
	ret
	ndisp endp
exit:	mov ah,4ch
	int 21h
code ends
end start
