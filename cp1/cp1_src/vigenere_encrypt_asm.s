.text
.globl vigenere_encrypt_asm

az:
  subl %ecx, %edx
  jmp iter
not_:
  popl %eax
  jmp iter

vigenere_encrypt_asm:

  pushl   %ebp
  movl    %esp,       %ebp

  movl 8(%esp),    %esi
  movl 12(%esp),   %edi
  movl 16(%esp),   %edx
  movl 20(%esp),   %ecx

iter:
  cld
  lodsb
  cmpb $0, %al
  je fin
  
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

  call is_alphabetic_c

  cmpl $0, %eax
  je not_

  popl %eax

  addl $4, %edx

  cmpl %edx, %ecx
  je az

  jmp iter
  
fin:
  movb $0, (%edi)
  leave
  ret

