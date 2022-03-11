.text
.globl caesar_encrypt_asm
caesar_encrypt_asm:

   pushl   %ebp
   movl    %esp,       %ebp

   movl 8(%esp), %esi
   movl 12(%esp), %edi
   movl 16(%esp), %ecx

iter:
   cld

   lodsb

   cmpb $0, %al
   je fin

   pushl %ecx
   pushl %eax
   call substitute_asm
   stosb
   popl %eax
   popl %ecx

   jmp iter

fin:
   movb $0, (%edi)
   leave
   ret
   

