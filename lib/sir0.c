#include "sir0.h"

/*
 * f'n to check chr array in file at offset 
 */
bool sir0_checkHeader(FILE* fp, int offset, char* header, size_t len) {
    fseek(fp, offset, SEEK_SET);    
    
    int i;
    for (i = 0; i < len; i++) {
        char check = fgetc(fp);
        if (check != header[i]) {
            return false;
        }
    }
    return true;

}
