#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include "utils.h"
#include "swdl.h"
#include "sir0.h"

void SWDL_print_header(struct SWDL_HEADER* swdl_header) {
    //printf("%.*s - ", 16, swdl_header->filename);

    printf("Time: ");
    SWDL_print_datetime(swdl_header);
    printf("\n");
    printf("PCMD Chunk Length: %" PRIu32 "\n", swdl_header->pcmdlen);
        
    printf("WAVI Sample Pointer Slots: %" PRIu16 "\n", swdl_header->nbwavislots);
    printf("PRGI Preset Pointer Slots: %" PRIu16 "\n", swdl_header->nbprgislots);

    printf("WAVI Chunk Length: %" PRIu32, swdl_header->wavilen);

    printf("\n");

}

void SWDL_print_datetime(struct SWDL_HEADER* swdl_header) {
    printf("%" PRIu8 "/%" PRIu8 "/%" PRIu16 " %02" PRIu8 ":%02" PRIu8 , \
        swdl_header->month, \
        swdl_header->day, \
        swdl_header->year, \
        swdl_header->hour, \
        swdl_header->minute \
    );

};

int SWDL_check_magic(struct SWDL_HEADER* header) {
    char swdl_magic[4] = {SWDL_MAGIC};
    return memcmp(header->magic, swdl_magic, sizeof(header->magic));
}

struct SWDL_CHUNK_HEADER* SWDL_read_chunk_header(FILE *fp) {
    size_t size = sizeof(struct SWDL_CHUNK_HEADER);

    void* header = file_read_bytes(fp, size);
    (struct SWDL_CHUNK_HEADER*)header;

    return header;
}

struct SWDL_HEADER* SWDL_create_header(FILE* fp, struct SIR0* sir0_header) {
    
    // go to SWDL file location
    fseek(fp, sir0_header->file_ptrs->swdl_ptr, SEEK_SET);
    // read in the SWDL header
    size_t size = sizeof(struct SWDL_HEADER);
    void* swdl_header = file_read_bytes(fp, size);
    (struct SWDL_HEADER*)swdl_header;

    if (SWDL_check_magic(swdl_header) != 0) {
        free(swdl_header);
        return NULL;
    }

    return swdl_header;
}