#ifndef __SE_RIPPER_PARSING__
#define __SE_RIPPER_PARSING__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "formats.h"


bool checkStr(FILE* fp, char* str); 
bool checkBuf(FILE* fp, char* buf, size_t len); 

int parse(FILE* fp);

#endif
