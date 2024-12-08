#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

byte MEMORY_GLOBAL[TAMANHO_MAXIMO] = {0};

bool free_space_bool(int start, int end) {
    for (int i = start; i < end; i++) {
        if (MEMORY_GLOBAL[i] != 0) {
            return false;
        }
    }
    return true;
}

byte* alocar(byte size) {
    for (int i = 0; i < TAMANHO_MAXIMO; i++) {
        if (MEMORY_GLOBAL[i] != 0) {
            i += MEMORY_GLOBAL[i];
            continue;
        }
        
        else if (!free_space_bool(i, i + size)) {
            continue;
        }

        else {
            MEMORY_GLOBAL[i] = size;
            return &MEMORY_GLOBAL[i + 1];
        }
    }
    return NULL;
}

void desalocar(void* address) {
    byte* start = (byte*)address;

    byte size = start[-1];
    start[-1] = 0;

    for (int i = 0; i < size; i++) {
        start[i] = 0;
    }
}