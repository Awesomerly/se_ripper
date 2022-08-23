#include <stdio.h>
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

    SWDL_print_header(swdl_header);

    SIR0_destroy(sir0_header);
    free(swdl_header);

    return 0;
}
