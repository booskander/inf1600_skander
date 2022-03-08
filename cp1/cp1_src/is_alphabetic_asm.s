.text
.globl is_alphabetic_asm
is_alphabetic_asm:

   # Si A = MOD(matricule, 2) = 0
   # laissez les lignes 10 et 11 commentees
   # Si A = MOD(matricule, 2) = 1
   # decommentez les lignes 10 et 11

   # pushl   %ebp
   # movl    %esp,   %ebp

   # Q3:

   # Si B = MOD(matricule, 1) = 0
   # Copiez le parametre dans %cl
   # Si B = MOD(matricule, 2) = 1
   # Copiez le parametre dans %ch
   # Si B = MOD(matricule, 2) = 2
   # Copiez le parametre dans %dh

   # Remplacez cette ligne par votre reponse a Q3
   mov 1(%esp), %ch
   # Ne pas modifiez les lignes qui precedent
   # excepte aux lignes 10, 11 et 22 tel qu'indique
   # dans les commentaires
   cmpb $'A', %ch
   jb false
   cmpb $'Z', %ch
   jbe bye
   cmpb $'a', %ch
   je false
   cmpb $'z', %ch
   jbe bye

false:
   mov $0, %eax
   # A COMPLETER




   # Ne pas modifiez les lignes qui suivent
   # excepte a la lignes 52 tel qu'indique
   # dans les commentaires
   
bye:

   # Q2:
   # Que faut il ajouter la?
   #leave

   ret

