#ifndef BIKE_STORE_H
#define BIKE_STORE_H

#include <stdint.h>

#define BIKE_STORE_MAX_NUMBER_MEASUREMENTS (32)

typedef struct
{
    uint16_t speed;
    uint16_t heartRate;
    uint16_t cadence;
    uint16_t power;
} bikeStoreMeasurement;

void bikeStoreAddMeasurement(bikeStoreMeasurement value);
uint16_t bikeStoreGetNumberOfMeasurementsPresent();
bikeStoreMeasurement bikeStoreGetMeasurement(uint16_t index_position);
uint16_t bikeStoreGetMaximumBikeStoreSize();

#endif
