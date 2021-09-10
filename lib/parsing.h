#ifndef __SE_RIPPER_PARSING__
#define __SE_RIPPER_PARSING__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIR0_H "SIR0" 

bool checkHeader(FILE* fp, int offset, char* header); 

#endif
