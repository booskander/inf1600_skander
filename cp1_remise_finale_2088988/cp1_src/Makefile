CC=gcc
CFLAGS=-g -m32 -g -Wall
RM=rm -f
TARGET=exec
OBJECTS=main.o c_functions.o vigenere_encrypt_asm.o caesar_encrypt_asm.o substitute_asm.o is_alphabetic_asm.o

.PHONY: clean

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.s.o:
	$(CC) $(CFLAGS) -c -o $@ $<

all: exec

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o $(TARGET)
