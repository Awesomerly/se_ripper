#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"
#include "sir0.h"
#include "swdl.h"


int parse(FILE* fp) {

    struct SIR0* sir0_header = SIR0_create(fp);
    if (sir0_header == NULL) return -1;

    struct SWDL_HEADER* swdl_header = SWDL_create_header(fp, sir0_header);
    if (swdl_header == NULL) return -2;

    printf("%.*s - ", 16, swdl_header->filename);
    //printf("%" PRIu8 "/%" PRIu8 "/%" PRIu16 " %02" PRIu8 ":%02" PRIu8 " - ", swdl_header->month, swdl_header->day, swdl_header->year, swdl_header->hour, swdl_header->minute);

    printf("wavi slots: %" PRIu16 " - ", swdl_header->nbwavislots);
    printf("wavi_len: %" PRIu32 , swdl_header->wavilen);

    printf("\n");

    SIR0_destroy(sir0_header);
    free(swdl_header);

    return 0;
}
