#include "operate.h"
#include <stdio.h>
#include <stdlib.h>

FILE* file = NULL;

int openFile(const char* fname) {
    file = fopen(fname, "r");
    if (file == NULL) {
        return -1;
    }
    return 0;
}

void closeFile() {
    if (file != NULL) {
        fclose(file);
        file = NULL;
    }
}