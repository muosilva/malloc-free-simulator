#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>
#define TAMANHO_MAXIMO 8192

typedef unsigned char byte;

byte* alocar(byte size);
void desalocar(void* address);
bool free_space_bool(int start, int end);

#endif