#include <stdio.h>
#include <stdlib.h>

#include "parsing.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Invalid Arguments\n");
        exit(-1);
    }
    char *filename = argv[1];

    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return(-2);
    }

    int result = parse(fp);

    if (result != 0) printf("%i\n", result);

    fclose(fp);

    return(0);
}
