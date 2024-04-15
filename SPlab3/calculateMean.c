#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculateMean.h"



// Mean Calculation Function
float Mean(const float *data, int valueCount) {
    float Sum = 0.0;
    for (int i = 0; i < valueCount; i++) {
        Sum += data[i];
    }
    return Sum / valueCount;
}

// Geometric Mean Calculation Function
float GeometricMean(const float *data, int valueCount) {
    if (valueCount == 0) {
        return 0;  // Undefined Geometric mean for Empty set 
    }
    double multiplication = 1.0;

    for (int i = 0; i < valueCount; i++) {
        if (data[i] <= 0) {
            return 0;  // Undefined Geometric mean for non-positive values
        }
        multiplication *= data[i];
    }
    return pow(multiplication, 1.0 / valueCount); // Calculate the geometric mean
}


// Harmonic Mean Calculation Function
float HarmonicMean(const float *data, int valueCount) {
    if (valueCount == 0) {
        return 0;  // Undefined Harmonic mean for Empty set 
    }
    double reciprocalAddition = 0.0;

    for (int i = 0; i < valueCount; i++) {
        if (data[i] == 0) {
            return 0;// if any value is zero, Harmonic mean is undefined 
        }
        reciprocalAddition += 1.0 / data[i];
    }
    return valueCount / reciprocalAddition;
}