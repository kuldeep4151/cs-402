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

// calculate Mode function
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

    // Checking if frequency of elements are same or not.
    if (Streak == 1) {
        *ModeCount = 0;
        return NULL;
    }

    // Check if all frequencies are the same
    bool frequencyCheck = true;
    for (int i = 1; i < valueCount; i++) {
        if (data[i] != data[0]) {
            frequencyCheck = false;
            break;
        }
    }

    if (frequencyCheck) {
        free(data);
        *ModeCount = 0;
        return NULL;
    }


    *ModeCount = Counter;
    
    // Memory allocation for the modes array
    float *modeArray = malloc(sizeof(float) * Counter);
    if (modeArray == NULL) {
        perror("Error! allocating memory");
        exit(1);
    }

    // loading data in the array
    for (int i = 0; i < Counter; i++) {
        modeArray[i] = modeData;
    }

    return modeArray;
}
