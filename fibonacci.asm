;nasm -f elf -l fibonacci.lst fibonacci.asm

SECTION .data
iteracoes:	db	8

SECTION .text

mov cx, iteracoes
mov al, 0 ;inicializa variavel [x1]
mov ah, 1 ;inicializa variavel [x2]
mov bl, 0 ;inicializa variavel onde sera gerada a sequencia [f]

inicio: cmp bl, 0 
jz primeiro ;pula na primeira iteração [caso bl = 0]
retornoPrimeiro: mov bl, al
add bl, ah
mov al, ah
mov ah, bl
loopnz inicio

primeiro:
mov bl, al
add bl, ah
jp retornoPrimeiro
