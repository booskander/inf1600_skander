#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "c_functions.h"
#include "asm_functions.h"

#define TEST_Q2_Q4 1
#define TEST_Q5_Q7 0
#define TEST_Q8 0
#define TEST_Q9 0

int main(int argc, char** argv) {

   // Validation du nombre de parametres du programme
   if(argc != 2) usage(argv[0]);

   // Initialition des chaines de caracteres
   char* salutation = malloc( sizeof(char) * 1024 );
   char* src        = malloc( sizeof(char) * 1024 );
   char* enc_c      = malloc( sizeof(char) * 1024 );
   char* enc_asm    = malloc( sizeof(char) * 1024 );
   char* keyword    = malloc( sizeof(char) * 1024 );
   char* str_test   = malloc( sizeof(char) * 1024 );
   
   init_with_string(salutation, "Mon matricule est ");
   init_with_string(str_test, "1H\\x|");
   init_with_string(src, "Vous jouez du xylophone dans un wagon bleu, \
tout en mangeant cinq kiwis frais.");
   init_with_string(keyword, argv[1]);
   
   // Parametres A, B, C et D du programme
   unsigned int matricule = atoi(argv[1]);
   unsigned int A, B, C, D;
   A = matricule % 2;
   B = matricule % 3;
   C = matricule % 5;
   D = matricule % 7;
   
   // Generation des cles d'encryption et de decryption
   unsigned int key = (A + B + C + D ) % 25 + 1;
   
   unsigned int encrypt_key = valid_key(key);
   unsigned int decrypt_key = decryption_key(key);
   
   unsigned int keyword_length = strlen(keyword);
   unsigned int * enc_keyword = malloc( sizeof(unsigned int) * keyword_length );
   unsigned int * dec_keyword = malloc( sizeof(unsigned int) * keyword_length );
   
   valid_keyword(keyword, enc_keyword);
   decryption_keyword(enc_keyword, dec_keyword, keyword_length);
   
   // Affichage
   printf("\n ** Controle periodique 1 ** \n\n");
   
   append_c( salutation, argv[1] );
   printf("%s\n", salutation);

   printf("A = %d, B = %d, C = %d, D = %d\n", A, B, C, D);
   printf("Key = %d\nEnc. key = %d\nDec. key = %d\n", key, encrypt_key, decrypt_key);
   printf("Keyword = %s\n", keyword);
   printf("Enc. keyword = ");
   print_array(enc_keyword, keyword_length);
   printf("Dec. keyword = ");
   print_array(dec_keyword, keyword_length);
   
   if( TEST_Q2_Q4 ){
   
      printf("\n- Q2-Q4 \n");
      
      for(int i=0; i<strlen(str_test); i++){
      
         char c         = str_test[i];
         bool test_asm  = is_alphabetic_asm( c );
         bool test_c    = is_alphabetic_c( c );
         
         printf("is_alphabetic_asm ");
         if( test_asm ^ test_c )
            printf("n'a pas vu que ");
         else
            printf("a vu que ");
         
         printf("'%c' ", c);
         
         if( test_c )
            printf("est ");
         else
            printf("n'est pas ");
            
         printf("une lettre.\n");
      }
      
      printf("\n");
   }
   
   if( TEST_Q5_Q7 ){
   
      printf("\n- Q5-Q7 \n");
      
      for(int i=0; i<strlen(str_test); i++){
      
         char c     = str_test[i];
         char c_asm = substitute_asm( c, key );
         char c_c   = substitute_c( c, key );
         
         printf("substitute_asm a substitue '%c' en '%c'", c, c_asm);
         
         if( c_asm ^ c_c )
            printf(", ce resultat n'est pas correct.\n");
         else
            printf(", ce resultat est correct.\n");
      }
      
      printf("\n");
   }
   
   if( TEST_Q8 ){
      
      printf("\n- Q8 \n");
      
      printf("Soit la phrase:\n%s\n", src);
      printf("Encryption de Cesar (ASM), cle %d:\n", encrypt_key);
      caesar_encrypt_asm(src, enc_asm, encrypt_key);
      printf("%s\n", enc_asm);
      printf("Encryption de Cesar (C), cle %d:\n", encrypt_key);
      caesar_encrypt_c(src, enc_c, encrypt_key);   
      printf("%s\n", enc_c);
      
      if( !strcmp(enc_asm, enc_c) )
         printf("Les encryptions concordent.\n\n");
      else
         printf("Les encryptions ne concordent pas.\n\n");
      
      printf("%s\n", enc_c);
      printf("Decryption de Cesar (ASM), cle %d:\n", decrypt_key);
      caesar_encrypt_asm(enc_c, enc_asm, decrypt_key);
      printf("%s\n", enc_asm);
      printf("Decryption de Cesar (C), cle %d:\n", decrypt_key);
      caesar_encrypt_c(enc_c, enc_c, decrypt_key);
      printf("%s\n", enc_c);
      
      if( !strcmp(enc_asm, enc_c) )
         printf("Les decryptions concordent.\n\n");
      else
         printf("Les decryptions ne concordent pas.\n\n");
   }
   
   if( TEST_Q9 ){
      printf("\n- Q9 \n");
      
      printf("Soit la phrase:\n%s\n", src);
      printf("Encryption de Vigenere (ASM), mot cle %s:\n", keyword);
      vigenere_encrypt_asm(src, enc_asm, enc_keyword, keyword_length);
      printf("%s\n", enc_asm);
      printf("Encryption de Vigenere (C), mot cle %s:\n", keyword);
      vigenere_encrypt_c(src, enc_c, enc_keyword, keyword_length);
      printf("%s\n", enc_c);
      
      if( !strcmp(enc_asm, enc_c) )
         printf("Les encryptions concordent.\n\n");
      else
         printf("Les encryptions ne concordent pas.\n\n");
      
      printf("Soit la phrase encryptee:\n%s\n", enc_c);
      printf("Decryption de Vigenere (ASM), mot cle %s:\n", keyword);
      vigenere_encrypt_asm(enc_c, enc_asm, dec_keyword, keyword_length);
      printf("%s\n", enc_asm);
      printf("Decryption de Vigenere (C), mot cle %s:\n", keyword);
      vigenere_encrypt_c(enc_c, enc_c, dec_keyword, keyword_length);
      printf("%s\n", enc_c);
      
      if( !strcmp(enc_asm, enc_c) )
         printf("Les decryptions concordent.\n\n");
      else
         printf("Les decryptions ne concordent pas.\n\n");
   }
   
   // Free allocated memory
   free(salutation);
   free(src);
   free(enc_c);
   free(enc_asm);
   free(keyword);
   free(str_test);
   free(enc_keyword);
   free(dec_keyword);

   return 0;
}

