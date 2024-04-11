#include "readfile.h"
#include "operate.h"
#include <stdio.h>
#include <stdlib.h>


int readint(int* intval) {
    if (file == NULL) {
        return -1;
    }
    return fscanf(file, "%d", intval);
}


int readstring(char* str, int maximumlength) {
    if (file == NULL) {
        return -1;
    }
    return fscanf(file, "%s", str);
}

int readfloat(float* intval) {
    if (file == NULL) {
        return -1;
    }
    return fscanf(file, "%f", intval);
}
