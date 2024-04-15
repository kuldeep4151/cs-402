#ifndef readPrint_H
#define readPrint_H

float *readFile(const char *filename, int *valueCount, int *array_capacity);
void printStats(int valueCount, int array_capacity, float mean, float median, float stddev, float *modes, int modesCount, float geometricMean, float harmonicMean);

#endif