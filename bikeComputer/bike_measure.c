#include "bike_measure.h"
#include <stdlib.h>

#define BIKE_COMPUTER_SIMULATOR_VALUE_MIN_SPEED (18)
#define BIKE_COMPUTER_SIMULATOR_VALUE_MAX_SPEED (24)

#define BIKE_COMPUTER_SIMULATOR_VALUE_MIN_POWER (150)
#define BIKE_COMPUTER_SIMULATOR_VALUE_MAX_POWER (200)

#define BIKE_COMPUTER_SIMULATOR_VALUE_MIN_HEART_RATE (130)
#define BIKE_COMPUTER_SIMULATOR_VALUE_MAX_HEART_RATE (140)

#define BIKE_COMPUTER_SIMULATOR_VALUE_MIN_CADENCE (88)
#define BIKE_COMPUTER_SIMULATOR_VALUE_MAX_CADENCE (98)

static uint16_t bikeComputerSimulatorGetRandomValue(uint16_t minRange, uint16_t maxRange)
{
    return minRange + (rand() % (maxRange - minRange));
}

uint16_t bikeMeasureSpeedInKmh()
{
    return bikeComputerSimulatorGetRandomValue(
        BIKE_COMPUTER_SIMULATOR_VALUE_MIN_SPEED,
        BIKE_COMPUTER_SIMULATOR_VALUE_MAX_SPEED);
}

uint16_t bikeMeasurePowerInWatt()
{
    return bikeComputerSimulatorGetRandomValue(
        BIKE_COMPUTER_SIMULATOR_VALUE_MIN_POWER,
        BIKE_COMPUTER_SIMULATOR_VALUE_MAX_POWER);
}

uint16_t bikeMeasureCadenceInRpm()
{
    return bikeComputerSimulatorGetRandomValue(
        BIKE_COMPUTER_SIMULATOR_VALUE_MIN_CADENCE,
        BIKE_COMPUTER_SIMULATOR_VALUE_MAX_CADENCE);
}

uint16_t bikeMeasureHeartRateInBpm()
{
    return bikeComputerSimulatorGetRandomValue(
        BIKE_COMPUTER_SIMULATOR_VALUE_MIN_HEART_RATE,
        BIKE_COMPUTER_SIMULATOR_VALUE_MAX_HEART_RATE);
}