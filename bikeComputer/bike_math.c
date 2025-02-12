#include "bike_math.h"

uint16_t bikeMathGetValueForDataType(bikeStoreMeasurement measurement, bikeDataType dataType)
{
    switch (dataType)
    {
        case BIKECADENCE: return measurement.cadence;
        case BIKESPEED: return measurement.speed;
        case BIKEHEARTRATE: return measurement.heartRate;
        case BIKEPOWER: return measurement.power;
        default: return 0;
    }
}

uint16_t bikeMathCalculateMinValue(bikeDataType dataType)
{
    uint16_t num_measurements = bikeStoreGetNumberOfMeasurementsPresent();
    uint16_t min_value = UINT16_MAX;

    for (uint16_t i = 0; i < num_measurements; i++)
    {
        uint16_t value = bikeMathGetValueForDataType(bikeStoreGetMeasurement(i), dataType);
        if (value < min_value) min_value = value;
    }

    return min_value;
}

uint16_t bikeMathCalculateMaxValue(bikeDataType dataType)
{
    uint16_t num_measurements = bikeStoreGetNumberOfMeasurementsPresent();
    uint16_t max_value = 0;

    for (uint16_t i = 0; i < num_measurements; i++)
    {
        uint16_t value = bikeMathGetValueForDataType(bikeStoreGetMeasurement(i), dataType);
        if (value > max_value) max_value = value;
    }

    return max_value;
}

uint16_t bikeMathCalculateAverageValue(bikeDataType dataType)
{
    uint16_t num_measurements = bikeStoreGetNumberOfMeasurementsPresent();
    if (num_measurements == 0) return 0;

    uint32_t sum = 0;
    for (uint16_t i = 0; i < num_measurements; i++)
    {
        sum += bikeMathGetValueForDataType(bikeStoreGetMeasurement(i), dataType);
    }

    return sum / num_measurements;
}
