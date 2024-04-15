#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "calculateMode.h"



// Function to check if all values in the dataset are unique
bool checkValues(const float *data, int valueCount) {
    for (int i = 0; i < valueCount - 1; i++) {
        for (int j = i + 1; j < valueCount; j++) {
            if (data[i] == data[j]) {
                return false;
            }
        }
    }
    return true;
}

// Modified calculateMode function
float *Mode(const float *data, int valueCount, int *ModeCount) {
    if (valueCount == 0 || checkValues(data, valueCount)) {
        *ModeCount = 0;
        return NULL;  // No mode for an empty set or when all values are unique
    }

    int Streak = 1;
    int Streakpointer = 1;
    int Counter = 1;
    float modeData = data[0];

    for (int i = 0; i < valueCount - 1; i++) {
        if (data[i] == data[i + 1]) {
            Streakpointer++;
        } else {
            Streakpointer = 1;
        }

        if (Streakpointer > Streak) {
            Streak = Streakpointer;
            Counter = 1;
            modeData = data[i];
        } else if (Streakpointer == Streak) {
            // If the current streak equals the maximum streak, consider it another mode
            Counter++;
        }
    }

    // Check if all values occurred only once
    if (Streak == 1) {
        *ModeCount = 0;
        return NULL;
    }

    *ModeCount = Counter;
    
    // Allocate memory for the modes array
    float *modeArray = malloc(sizeof(float) * Counter);
    if (modeArray == NULL) {
        perror("Error! allocating memory");
        exit(1);
    }

    // Fill the modes array
    for (int i = 0; i < Counter; i++) {
        modeArray[i] = modeData;
    }

    return modeArray;
}
