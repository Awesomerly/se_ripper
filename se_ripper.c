#include <stdio.h>
#include <stdlib.h>

#include "lib/sir0.h"

int main(int argc, char *argv[]) {

	if (argc != 2) {
		printf("invalid # of arguments Lol");
		exit(0);
	}
	char *filename = argv[1];

    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("File cannot be opened.");
        return(1);
    }

    char sir0h[] = HEADER_SIR0; 

    int check = sir0_checkHeader(fp, 0, sir0h, sizeof(sir0h));
    printf("SIR0_headercheck %i\n", check);

    fclose(fp);

	return(0);
}