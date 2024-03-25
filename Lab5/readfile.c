#include "readfile.h"
#include "operate.h"
#include <stdio.h>
#include <stdlib.h>


int readint(int* value) {
    if (file == NULL) {
        return -1;
    }
    return fscanf(file, "%d", value);
}


int readstring(char* str, int maximumlength) {
    if (file == NULL) {
        return -1;
    }
    return fscanf(file, "%s", str);
}

int readfloat(float* value) {
    if (file == NULL) {
        return -1;
    }
    return fscanf(file, "%f", value);
}
