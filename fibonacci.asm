;nasm -f elf -l fibonacci.lst fibonacci.asm

	SECTION .data
i:	dd 8;
iteracoes:	dd 5 ;define o numero de iteracoes

	SECTION .text
	global main

main:
	;mov ecx, iteracoes ;usar em caso de debug
	mov cx, iteracoes
	mov al, 0 ;inicializa variavel [x1]
	mov ah, 1 ;inicializa variavel [x2]
	mov bl, 0 ;inicializa variavel onde sera gerada a sequencia [f]

inicio:
	cmp bl, 0 
	jz primeiro ;pula na primeira iteração [caso bl = 0]
retorno:	mov bl, al
	add bl, ah
	mov al, ah
	mov ah, bl
	loopnz inicio
	hlt ;usar no simulador
	
	;mov ebx,0 ;sair e retornar para o sistema
	;mov eax,1 ;usar em caso de debug
	;int 0x80 ;
primeiro:
	mov bl, al
	add bl, ah
	jmp retorno
