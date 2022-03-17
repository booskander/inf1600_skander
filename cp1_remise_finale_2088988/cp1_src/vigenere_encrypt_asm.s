.text
.globl vigenere_encrypt_asm

az:
  movl $0, %edx
  jmp bye
not_:
  popl %eax
  jmp iter
fin:
  popl %eax
  jmp bye

vigenere_encrypt_asm:

  pushl   %ebp
  movl    %esp,       %ebp

  movl 8(%esp),    %esi
  movl 12(%esp),   %edi
  movl 16(%esp),   %edx
  movl 20(%esp),   %ecx
  movl $0, %eax
  

iter:
  cld

  cmpl %ecx, %eax # ces lignes la le neuvelent pas se faire executer
                  # mon code semble fonctionner pour les 8 premiers
                  # caracteres de la string, mais ne permet pas de revenir
                  #au premier element apres 8 iterations.    
  je az


  push %eax
  lodsb
  cmpb $0, %al
  je bye
  
  pushl %edx
  movl (%edx), %edx
  pushl %edx

  pushl %eax
  
  call substitute_c
  stosb

  popl %eax
  popl %edx
  popl %edx

  pushl %eax

  call is_alphabetic_asm


  cmpl $0, %eax
  je not_

  popl %eax
  popl %eax

  addl $1, %eax

  addl $4, %edx

  jmp iter


  
bye:
  movb $0, (%edi)
  leave
  ret

