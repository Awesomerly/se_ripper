#include "parsing.h"

/*
 * f'n to check chr array in file at offset 
 * uses null terminated strings to represent header
 */
bool checkStr(FILE* fp, char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        char check = fgetc(fp);
        if (check != str[i]) {
            return false;
        }
    }
    return true;
}

bool checkBuf(FILE* fp, char* buf, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        char check = fgetc(fp);
        if (check != buf[i]) {
            return false;
        }
    }
    return true;
}
