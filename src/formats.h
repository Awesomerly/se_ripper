#ifndef __SE_RIPPER_FORMATS__
#define __SE_RIPPER_FORMATS__

#define SIR0_MAGIC 'S', 'I', 'R', '0'
#define SWDL_MAGIC 's', 'w', 'd', 'l'

#include <stdint.h>

// unless specified, everything here is little endian.

struct SIR0_HEADER {
    char magic[4];

    // pointer to SIR0_FILE_PTRS
    uint32_t file_ptrs_ptr;

    // points to pointer offsets
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
    struct SIR0_HEADER header;
    struct SIR0_FILE_PTRS file_ptrs;
};

struct SWDL_HEADER {
    char magic[4];
    uint32_t _padding0;
    uint32_t file_length;
    uint16_t version;

    uint16_t _unk0;

    uint64_t _padding1;

    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t centisecond;

    char filename[16];

    uint64_t _unk10;
    uint32_t _unk12;
    uint32_t _unk13;

    uint32_t pmcdlen;

    uint32_t unk14;

    uint16_t nbwavislots;
    uint16_t nbprislots;

    uint32_t wavilen;

};

#endif
