#ifndef __SE_RIPPER_WAVI__
#define __SE_RIPPER_WAVI__

#include <stdint.h>
//#include "swdl.h"

struct __attribute__((__packed__)) WAVI_SampleInfo {
    uint16_t _unk1;

    uint16_t index;
    int8_t ftune;
    int8_t ctune;

    int8_t rootkey;
    int8_t ktps;
    int8_t volume;
    int8_t pan;

    uint8_t unk5;
    uint8_t unk58;
    uint32_t _padding;
    uint16_t unk59;

    uint16_t smplfmt;
    uint8_t unk9;
    uint8_t smplloop;

    uint16_t unk10;
    uint16_t unk11;
    uint16_t unk12;
    uint32_t unk13;

    uint32_t smplrate;
    uint32_t smplpos;
    uint32_t loopbeg;
    uint32_t looplen;

    uint8_t envon;
    uint8_t envmult;

    uint8_t unk19;
    uint8_t unk20;
    uint16_t unk21;
    uint16_t unk22;

    int8_t atkvol;
    int8_t attack;
    int8_t decay;
    int8_t sustain;
    int8_t hold;
    int8_t decay2;
    int8_t release;
    int8_t unk57;

};


#endif