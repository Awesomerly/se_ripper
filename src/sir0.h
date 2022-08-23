#ifndef __SE_RIPPER_SIR0__
#define __SE_RIPPER_SIR0__

#define SIR0_MAGIC 'S', 'I', 'R', '0'

#include <stdint.h>
#include <stdio.h>

struct SIR0* SIR0_create(FILE* fp);
int SIR0_check_magic(FILE* fp, struct SIR0* wrapper);
void SIR0_read_header(FILE* fp, struct SIR0* wrapper);
void SIR0_read_pointers(FILE* fp, struct SIR0* wrapper);
void SIR0_destroy(struct SIR0* wrapper);

// unless specified, everything here is little endian.

struct SIR0_HEADER {
    char magic[4];

    // pointer to SIR0_FILE_PTRS
    uint32_t file_ptrs_ptr;

    // points to pointer offsets (maps file locations to ds memory locations)
    // this is outside the scope of my project :)
    uint32_t pointer_offset_ptr;

    uint32_t _padding;
};

struct SIR0_FILE_PTRS {
    uint32_t swdl_ptr;
    uint32_t sedl_ptr;
    uint64_t _padding;
};

struct SIR0 {
    struct SIR0_HEADER* header;
    struct SIR0_FILE_PTRS* file_ptrs;
};

#endif
