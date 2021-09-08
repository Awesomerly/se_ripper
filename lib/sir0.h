#ifndef __SE_RIPPER_SIR0__
#define __SE_RIPPER_SIR0__

#include <stdio.h>

#define HEADER_SIR0 {'S', 'I', 'R', '0'}

int sir0_checkHeader(FILE* fp, int offset, char* header, size_t len); 

#endif
