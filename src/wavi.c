#include <stdio.h>
#include "wavi.h"
#include "utils.h"

struct WAVI_SampleInfo* WAVI_read_sampleinfo(FILE* fp) {
    size_t size = sizeof(struct WAVI_SampleInfo);

    void* table = file_read_bytes(fp, size);
    (struct WAVI_SampleInfo*)table;

    return table;
};