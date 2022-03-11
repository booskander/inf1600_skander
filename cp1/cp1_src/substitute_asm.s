.text
.globl substitute_asm
not_1:
   sub $26,          %di
   jmp fin
not_2:
   pop               %si
   pop               %di
   jmp not_1
substitute_asm:

   pushl   %ebp
   movl    %esp,     %ebp
   
   mov 8(%esp),      %si 
   movl 12(%esp),    %ecx
   mov %si,          %di

   pushl %edi
   call is_alphabetic_asm
   pop %di
   
   cmpl $0,          %eax
   je fin

   addl %ecx,        %edi


   push %di
   call is_alphabetic_asm
   pop %di

   cmpl $0,          %eax
   je not_1

   push              %di
   push              %si

   and $0x20,        %di
   and $0x20,        %si

   cmp %si,          %di
   jne not_2

   pop               %si
   pop               %di
fin:
   movl %edi,        %eax
   leave
   ret

