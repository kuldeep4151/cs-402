#ifndef OPERATE_H
#define OPERATE_H
#include <stdio.h>
#include <stdlib.h>

extern FILE* file;

int openFile(const char* fname);
void closeFile();

#endif 