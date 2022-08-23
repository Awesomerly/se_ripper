#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"
#include "sir0.h"
#include "swdl.h"

char swdl_magic[4] = {SWDL_MAGIC};

int parse(FILE* fp) {

    struct SIR0* sir0 = SIR0_create(fp);
    if (sir0 == NULL) return -1;

    struct SWDL_HEADER swdl_h;
    // go to swdl
    fseek(fp, sir0->file_ptrs->swdl_ptr, SEEK_SET);

    char swdl_magic[4] = {SWDL_MAGIC};
    // read in the SWDL header
    fread(&swdl_h, sizeof(uint8_t), sizeof(struct SWDL_HEADER), fp);
    if (memcmp(swdl_h.magic, swdl_magic, sizeof(swdl_h.magic)) != 0) return -2; // not a swdl container

    printf("%.*s - ", 16, swdl_h.filename);
    printf("%" PRIu8 "/%" PRIu8 "/%" PRIu16 " %02" PRIu8 ":%02" PRIu8 " - ", swdl_h.month, swdl_h.day, swdl_h.year, swdl_h.hour, swdl_h.minute);

    printf("wavi slots: %" PRIu16 " - ", swdl_h.nbwavislots);
    printf("wavi_len: %" PRIu32 , swdl_h.wavilen);

    printf("\n");

    SIR0_destroy(sir0);

    return 0;
}
