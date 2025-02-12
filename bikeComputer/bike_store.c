#include "bike_store.h"

static bikeStoreMeasurement bikeStoreArray[BIKE_STORE_MAX_NUMBER_MEASUREMENTS] = { {0,} };
static uint16_t bikeStoreNumberOfMeasurementsPresent = 0;

uint16_t bikeStoreGetMaximumBikeStoreSize()
{
    return BIKE_STORE_MAX_NUMBER_MEASUREMENTS;
}

void bikeStoreAddMeasurement(bikeStoreMeasurement value)
{
    if (bikeStoreNumberOfMeasurementsPresent >= bikeStoreGetMaximumBikeStoreSize())
    {
        bikeStoreNumberOfMeasurementsPresent = 0;
    }

    bikeStoreArray[bikeStoreNumberOfMeasurementsPresent++] = value;
}

uint16_t bikeStoreGetNumberOfMeasurementsPresent()
{
    return bikeStoreNumberOfMeasurementsPresent;
}

bikeStoreMeasurement bikeStoreGetMeasurement(uint16_t indexPosition)
{
    return bikeStoreArray[indexPosition];
}
