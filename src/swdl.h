#ifndef __SE_RIPPER_SWDL__
#define __SE_RIPPER_SWDL__

#include <stdint.h>
#include "sir0.h"

#define SWDL_MAGIC 's', 'w', 'd', 'l'

struct SWDL_HEADER* SWDL_create_header(FILE* fp, struct SIR0* sir0_header);

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