#ifndef C_FUNCTIONS
#define C_FUNCTIONS

void usage(const char* program);
void init_with_string(char* dst, const char* src);

void append_c(char* dst, const char* src);
void print_array(unsigned int * array, unsigned int length);

unsigned int valid_key(const unsigned int key);
unsigned int decryption_key(const unsigned int key);
void valid_keyword(const char * keyword, unsigned int * vk);
void decryption_keyword(const unsigned int * enc_keyword, 
                        unsigned int * dec_keyword, unsigned int length);

int  is_alphabetic_c(const char c);
char substitute_c(const char src, const unsigned int key);
void caesar_encrypt_c(const char* src, char*dst, 
                      const unsigned int key);
void vigenere_encrypt_c(const char* src, char*dst, 
                        const unsigned int * keyword, 
                        const unsigned int kw_length);

#endif
