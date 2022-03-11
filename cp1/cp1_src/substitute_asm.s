.text
.globl substitute_asm
not_1:
   subl $26, %edi
   jmp fin
not_2:
   popl               %esi
   popl               %edi
   jmp not_1
substitute_asm:

   pushl   %ebp
   movl    %esp,     %ebp
   
   movl 8(%esp),      %esi 
   movl 12(%esp),     %ecx
   movl %esi,         %edi

   pushl %edi
   call is_alphabetic_asm
   popl %edi
   
   cmpl $0,          %eax
   je fin

   addl %ecx,        %edi


   pushl %edi
   call is_alphabetic_asm
   popl %edi

   cmpl $0,          %eax
   je not_1

   pushl             %edi
   pushl             %esi

   and $0x20,        %edi
   and $0x20,        %esi

   cmpl %esi,        %edi
   jne not_2

   popl              %esi
   popl              %edi
fin:
   movl %edi,        %eax
   leave
   ret

