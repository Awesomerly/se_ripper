#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "swdl.h"
#include "sir0.h"

int SWDL_check_magic(struct SWDL_HEADER* header) {
    char swdl_magic[4] = {SWDL_MAGIC};
    return memcmp(header->magic, swdl_magic, sizeof(header->magic));
}

struct SWDL_HEADER* SWDL_create_header(FILE* fp, struct SIR0* sir0_header) {
    size_t header_size = sizeof(struct SWDL_HEADER);
    struct SWDL_HEADER* swdl_header = malloc(header_size);
    
    // go to SWDL file location
    fseek(fp, sir0_header->file_ptrs->swdl_ptr, SEEK_SET);
    // read in the SWDL header
    fread(swdl_header, sizeof(uint8_t), header_size, fp);

    if (SWDL_check_magic(swdl_header) != 0) {
        free(swdl_header);
        return NULL;
    }

    return swdl_header;
}