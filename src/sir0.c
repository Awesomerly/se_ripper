#include <stdlib.h>
#include <string.h>
#include "sir0.h"
#include "utils.h"

// copy SIR0 header into wrapper
void SIR0_read_header(FILE* fp, struct SIR0* wrapper) {
    // go to beginning of file
    fseek(fp, 0, SEEK_SET);
    // read in header
    void* temp_header = file_read_bytes(fp, sizeof(struct SIR0_HEADER));
    (struct SIR0_HEADER*)temp_header;
    
    wrapper->header = temp_header;
}

// go to the file pointer offsets and read that into the wrapper
void SIR0_read_pointers(FILE* fp, struct SIR0* wrapper) {
    fseek(fp, wrapper->header->file_ptrs_ptr, SEEK_SET);
    // read the swdl and sedl pointer table into the temp file ptrs data
    size_t size = sizeof(struct SIR0_FILE_PTRS);
    void* temp_ptrs = file_read_bytes(fp, size);
    (struct SIR0_FILE_PTRS*)temp_ptrs;

    wrapper->file_ptrs = temp_ptrs;
}

// check the magic string
int SIR0_check_magic(FILE* fp, struct SIR0* wrapper) {
    char sir0_magic[4] = {SIR0_MAGIC};
    int compare_headers = memcmp(wrapper->header->magic, sir0_magic, sizeof(sir0_magic));

    return compare_headers;
}

void SIR0_destroy(struct SIR0* wrapper) {
    free(wrapper->header);
    free(wrapper->file_ptrs);
    free(wrapper);
}

struct SIR0* SIR0_create(FILE* fp) {
    struct SIR0* wrapper = malloc(sizeof(struct SIR0));

    SIR0_read_header(fp, wrapper);

    int check = SIR0_check_magic(fp, wrapper); 

    // abort if magic check fails
    if (check != 0) {
        free(wrapper->header);
        free(wrapper);
        return NULL;
    }

    SIR0_read_pointers(fp, wrapper);

    // go to beginning of file
    fseek(fp, 0, SEEK_SET);

    return wrapper;
}