#ifndef ASM_FUNCTIONS
#define ASM_FUNCTIONS

extern int  is_alphabetic_asm(const char c);
extern char substitute_asm(const char src, const unsigned int key);
extern void caesar_encrypt_asm(const char* src, char*dst, 
                               const unsigned int key);
extern void vigenere_encrypt_asm(const char* src, char*dst, 
                        const unsigned int * keyword, 
                        const unsigned int kw_length);

#endif
