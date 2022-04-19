#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"
#include "formats.h"

char sir0_magic[4] = {SIR0_MAGIC};
char swdl_magic[4] = {SWDL_MAGIC};


struct SIR0* SIR0_create(FILE* fp) {
    struct SIR0* wrapper = malloc(sizeof(struct SIR0));
    struct SIR0_HEADER header;
    struct SIR0_FILE_PTRS ptrs;
    // read in SIR0 header
    fread(&header, sizeof(uint8_t), sizeof(struct SIR0_HEADER), fp);
    if (memcmp(&(header.magic), sir0_magic, sizeof(sir0_magic)) != 0) return NULL; // not a sir0 container
    wrapper->header = header;

    long pos = ftell(fp);
    fseek(fp, wrapper->header.file_ptrs_ptr, SEEK_SET);

    fread(&ptrs, sizeof(uint8_t), sizeof(struct SIR0_FILE_PTRS), fp);
    wrapper->file_ptrs = ptrs;

    printf("%i - ", wrapper->file_ptrs.sedl_ptr);
    fseek(fp, pos, SEEK_SET);

    return wrapper;
}


int parse(FILE* fp) {

    struct SIR0* sir0_container = SIR0_create(fp);
    printf("%.*s - ", 4, sir0_container->header.magic);

    struct SWDL_HEADER swdl_h;
    char swdl_magic[4] = {SWDL_MAGIC};

    // go to swdl
    fseek(fp, sir0_container->file_ptrs.swdl_ptr, SEEK_SET);

    // read in the SWDL header
    fread(&swdl_h, sizeof(uint8_t), sizeof(struct SWDL_HEADER), fp);
    if (memcmp(swdl_h.magic, swdl_magic, sizeof(swdl_h.magic)) != 0) return -2; // not a swdl container

    printf("%.*s - ", 16, swdl_h.filename);
    printf("%" PRIu8 "/%" PRIu8 "/%" PRIu16 " %02" PRIu8 ":%02" PRIu8 "\n", swdl_h.month, swdl_h.day, swdl_h.year, swdl_h.hour, swdl_h.minute);

    return 0;
}
