#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

// may make it platform dependent
#include <byteswap.h>

#include "parsing.h"
#include "formats.h"

int parse(FILE* fp) {

    struct SIR0_HEADER sir0_h;
    char sir0_magic[4] = {SIR0_MAGIC};    

    // read in SIR0 header
    fread(&sir0_h, sizeof(uint8_t), sizeof(struct SIR0_HEADER), fp);
    
    if (memcmp(sir0_h.magic, sir0_magic, sizeof(sir0_h.magic)) != 0) return -1; // not a sir0 container


    struct SWDL_HEADER swdl_h;
    char swdl_magic[4] = {SWDL_MAGIC};

    // skip to after padding in file
    fseek(fp, 0x40, SEEK_SET);

    // read in the SWDL header
    fread(&swdl_h, sizeof(uint8_t), sizeof(struct SWDL_HEADER), fp);
    if (memcmp(swdl_h.magic, swdl_magic, sizeof(swdl_h.magic)) != 0) return -2; // not a swdl container

    printf("%.*s - ", 16, swdl_h.filename);
    printf("%" PRIu8 "/%" PRIu8 "/%" PRIu16 " %02" PRIu8 ":%02" PRIu8 "\n", swdl_h.month, swdl_h.day, swdl_h.year, swdl_h.hour, swdl_h.minute);

    return 0;
}
