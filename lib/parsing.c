#include "parsing.h"

/*
 * f'n to check chr array in file at offset 
 * uses null terminated strings to represent header
 */
bool checkHeader(FILE* fp, int offset, char* header) {
    fseek(fp, offset, SEEK_SET);    
    
    int i;
    for (i = 0; header[i] != '\0'; i++) {
        char check = fgetc(fp);
        if (check != header[i]) {
            return false;
        }
    }
    return true;
}
