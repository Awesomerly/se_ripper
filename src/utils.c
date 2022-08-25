#include <stdint.h>
#include <stdlib.h>
#include "utils.h"

// TODO: add error handling somehow because this is sketch
void* file_read_bytes(FILE *fp, size_t size) {
    
    void* data = malloc(size);
    fread(data, sizeof(uint8_t), size, fp);

    return data;
}