; Gerador da serie fibonacci
;
; A serie é gerada no registrador BL
;
; Para compilar use o seguinte commando em um terminal:
;nasm -f elf -l fibonacci.lst fibonacci.asm

	SECTION .data
iteracoes:  db 4 ;define o numero de iteracoes

	SECTION .text
	global main
main:
	;mov ecx, iteracoes ;usar em caso de debug
	mov cx, iteracoes
	mov al, 1 ;inicializa variavel [x1]
	mov ah, 1 ;inicializa variavel [x2]
	mov bl, 0 ;inicializa variavel onde sera gerada a sequencia [f]
inicio:
	cmp bl, 0
	jz primeiro ;pula na primeira iteração [caso bl = 0]
 
retorno: ;parteA bl = bl + al ; al = bl
	add bl, al
	mov al, bl      
	 ;parteB bl = bl + ah ; ah = bl
	add bl, ah
	mov ah, bl    
	loopnz retorno
 	
	hlt ;usar no simulador

primeiro: ;é só uma coisa besta para o "bl" receber os dois primeiros elementos da série "1 e 1"
	mov bl, al ;bl = 1
	mov bl, ah ;bl = 1
	jmp retorno

