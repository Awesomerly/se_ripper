#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsing.h"
#include "sir0.h"
#include "swdl.h"
#include "wavi.h"

int parse(FILE* fp) {

    struct SIR0* sir0_header = SIR0_create(fp);
    if (sir0_header == NULL) return -1;

    struct SWDL_HEADER* swdl_header = SWDL_create_header(fp, sir0_header);
    if (swdl_header == NULL) return -2;

    SWDL_print_header(swdl_header);

    // read in wavi chunk header
    struct SWDL_CHUNK_HEADER* wavi_chunk_header = SWDL_read_chunk_header(fp);
    size_t wavi_begin = ftell(fp);

    uint16_t offset = 0;
    // 0xAAAA is the delimiter, 0xAA01 is the start of the first sampleinfotbl. 
    while (offset != 0xAAAA && offset != 0xAA01) {
        size_t wavi_cur = ftell(fp);
        if (offset != 0) {
            printf("%i", offset);
            fseek(fp, wavi_begin + offset, SEEK_SET);
            // do stuff
            struct WAVI_SampleInfo* tbl = WAVI_read_sampleinfo(fp);
            
            printf(" - offset %lu at %lukHz of format 0x%.4X\n", tbl->smplpos, tbl->smplrate, tbl->smplfmt);

            free(tbl);
            fseek(fp, wavi_cur, SEEK_SET);
        }
        fread(&offset, sizeof(uint16_t), 1, fp);
    };
    
    printf("\n\n");
    SIR0_destroy(sir0_header);
    free(swdl_header);

    return 0;
}
