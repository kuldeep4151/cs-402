#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculateMedian.h"


// Mean Calculation Function
float Median(float *data, int valueCount) {
    //for-loop for sorting-up the data
    for (int i = 0; i < valueCount - 1; i++) {
        for (int j = 0; j < valueCount - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                float temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    //condition check for Even & Odd number of values 
    if (valueCount % 2 == 0) {
        int midvalue1 = valueCount / 2 - 1;
        int midvalue2 = valueCount / 2;
        return (data[midvalue1] + data[midvalue2]) / 2.0;
    } else {
        return data[valueCount / 2];
    }
}

// Standard deviation Calculation Function
float StandardDeviation(const float *data, int valueCount, float mean) {
    float Addition = 0.0;
    for (int i = 0; i < valueCount; i++) {
        Addition += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(Addition / valueCount);
}