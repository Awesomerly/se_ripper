#ifndef __SE_RIPPER_PARSING__
#define __SE_RIPPER_PARSING__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIR0_H {'S', 'I', 'R', '0'}

bool sir0_checkHeader(FILE* fp, int offset, char* header, size_t len); 

#endif
