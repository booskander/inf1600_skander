.text
.globl vigenere_encrypt_asm
 vigenere_encrypt_asm :

   pushl   %ebp
   movl    %esp,       %ebp

   movl 8(%esp),    %esi
   movl 12(%esp),   %edi
   movl 16(%esp),   %edx
   movl 20(%esp),   %ecx




   leave
   ret

