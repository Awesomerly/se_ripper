#ifndef __SE_RIPPER_PARSING__
#define __SE_RIPPER_PARSING__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIR0_H "SIR0" 

bool checkStr(FILE* fp, char* str); 
bool checkBuf(FILE* fp, char* buf, size_t len); 

#endif
