#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_functions.h"

void usage(const char* program) {
   fprintf(stderr, "Usage:\n\t%s matricule\n", program);
   exit(1);
}

void init_with_string(char* dst, const char* src){
   unsigned int i = 0;
   while(src[i] != 0){
      dst[i] = src[i];
      i++;
   }
}

void append_c(char* dst, const char* src){

   unsigned int i = 0, j = 0;

   while( dst[j] != 0 ) j++;

   while( src[i] != 0 )
      dst[j++] = src[i++];

   dst[j] = '\0';
}

void print_array(unsigned int * array, unsigned int length){
   for(int i = 0; i < length; i++) 
      printf("%d ", array[i]);
   printf("\n");
} 

unsigned int valid_key(const unsigned int key){
   return key%26;
}

unsigned int decryption_key(const unsigned int key){
   return (26 - valid_key(key)) % 26;
}

void valid_keyword(const char * keyword, unsigned int * vk){
   unsigned int i = 0;
   while( keyword[i] != 0 ){
      vk[i] = valid_key((unsigned int) keyword[i]);
      i++;
   }
}

void decryption_keyword(const unsigned int * enc_keyword, 
                        unsigned int * dec_keyword, 
                        unsigned int length){
   for(int i = 0; i < length; i++){
      dec_keyword[i] = decryption_key(enc_keyword[i]);
   }
}


int is_alphabetic_c(const char c){
   if( ( c >= 'A' && c <= 'Z') ||
       ( c >= 'a' && c <= 'z') )
      return 1;
   return 0;
}

char substitute_c(const char src, const unsigned int key){
   char dst = src;
   if( is_alphabetic_c( dst ) ){
      dst += key;
      if( !is_alphabetic_c( dst ) ) 
         dst -= 26;
      else if( (src & 0x20) != (dst & 0x20) )
         dst -= 26;
   }   
   return dst;
}

void caesar_encrypt_c(const char* src, char*dst, 
                      const unsigned int key){
   unsigned int i = 0;
   while( src[i] != 0 ){
      dst[i] = substitute_c(src[i], key);
      i++;
   }
   dst[i] = '\0';
}

void vigenere_encrypt_c(const char* src, char*dst, 
                        const unsigned int * keyword, 
                        const unsigned int kw_length){
   unsigned int i = 0, j = 0;
   while( src[i] != 0 ){
      dst[i] = substitute_c(src[i], keyword[j]);
      i++;
      if( is_alphabetic_c( src[i] ) ){
         j++;
         if( j == kw_length )
            j = 0;
      }
   }
   dst[i] = '\0';
}

