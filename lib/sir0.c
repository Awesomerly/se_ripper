#include "sir0.h"

/*
 * Bring it to the beginning and check if the header is right 
 */
int sir0_checkHeader(FILE* fp, int offset, char* header, size_t len) {
    fseek(fp, offset, SEEK_SET);    
    
    int i;
    for (i = 0; i < len; i++) {
        char check = fgetc(fp);
        if (check != header[i]) {
            return 0;
        }
    }
    return 1;

}
