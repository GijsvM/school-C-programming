#ifndef BIKE_MATH_H
#define BIKE_MATH_H

#include "bike_store.h"

typedef enum {
    BIKESPEED,
    BIKEHEARTRATE,
    BIKECADENCE,
    BIKEPOWER
} bikeDataType;

uint16_t bikeMathCalculateMinValue(bikeDataType dataType);
uint16_t bikeMathCalculateMaxValue(bikeDataType dataType);
uint16_t bikeMathCalculateAverageValue(bikeDataType dataType);
uint16_t bikeMathGetValueForDataType(bikeStoreMeasurement measurement, bikeDataType dataType);

#endif