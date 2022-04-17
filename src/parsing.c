#include "parsing.h"
#include "formats.h"

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

int parse(FILE* fp) {
    if (!checkStr(fp, SIR0_H)) {
        printf("NOT A VALID SIR0 CONTAINER\n");
        return 1;
    }
    printf("SIR0 CHECK VALID\n");

    // since I won't be dealing with ptr offsets i can skip to 0x40
    fseek(fp, 0x40, SEEK_SET);
    if (!checkStr(fp, SWDL_H)) {
        printf("NO SWDL HEADER FOUND\n");
        return 2;
    }
    printf("SWDL_CHK_VALID\n");

    return 0;
}
