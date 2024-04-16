#include <stdio.h>
#include <stdlib.h>
#include "readPrint.h"


// Function to read data from a file and store it in a dynamically allocated array
float *readFile(const char *filename, int *valueCount, int *array_capacity) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error! unable to open file");
        exit(1);
    }

    *array_capacity = 20; // Initial capacity of the array
    *valueCount = 0;
    float *data = (float *)malloc(sizeof(float) * *array_capacity);

    if (data == NULL) {
        perror("Error! for allocating memory");
        exit(1);
    }

    float value;
    while (fscanf(file, "%f", &value) == 1) {
        if (*valueCount == *array_capacity) {
            // If the array is full, allocate a new array with double the capacity
            *array_capacity *= 2;
            data = (float *)realloc(data, sizeof(float) * *array_capacity);
            if (data == NULL) {
                perror("Error reallocating memory");
                exit(1);
            }
        }
        data[(*valueCount)++] = value;
    }

    fclose(file);
    return data;
}


// Function to print the results
void printStats(int valueCount, int array_capacity, float mean, float median, float stddev, float *modes, int modesCount, float geometricMean, float harmonicMean) {
    printf("Results:\n");
    printf("--------\n");
    printf("Num values:            %d\n", valueCount);
    printf("      mean:        %.3f\n", mean);
    printf("    median:        %.3f\n", median);
    printf("    stddev:        %.3f\n", stddev);

    if (modesCount == 0) {
        printf("      mode:  No mode found.\n");
    } else {
        printf("      mode(s):");
        for (int i = 0; i < modesCount; i++) {
            printf(" %.3f", modes[i]);
        }
        printf("\n");
    }

    printf("  geometric mean:  %.3f\n", geometricMean);
    printf("  harmonic mean:   %.3f\n", harmonicMean);
    printf("Unused array capacity: %d\n", array_capacity - valueCount);
}