#include <stdio.h>
#include <stdlib.h>
#include "calculateMean.h"
#include "calculateMedian.h"
#include "calculateMode.h"
#include "readPrint.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int valueCount, array_capacity, modesCount;
    float *data = readFile(filename, &valueCount, &array_capacity);

    if (valueCount == 0) {
        printf("The Input file is Empty(No data).\n");
        free(data);
        return 1;
    }

    float mean = Mean(data, valueCount);
    float median = Median(data, valueCount);
    float stddev = StandardDeviation(data, valueCount, mean);
    float *modes = Mode(data, valueCount, &modesCount);
    float geometricMean = GeometricMean(data, valueCount);
    float harmonicMean = HarmonicMean(data, valueCount);

    printStats(valueCount, array_capacity, mean, median, stddev, modes, modesCount, geometricMean, harmonicMean);

    free(data);
    free(modes);
    return 0;
}