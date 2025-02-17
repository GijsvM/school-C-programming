#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bike_store.h"
#include "bike_math.h"
#include "bike_measure.h"

int main()
{
    bikeStoreMeasurement measurement;
    bikeDataType dataTypes[] = { BIKESPEED, BIKECADENCE, BIKEHEARTRATE, BIKEPOWER };
    const char* labels[] = { "SPEED", "CADENCE", "HEART-RATE", "POWER" };
    const char* units[] = { "[km/h]", "[rpm]", "[hrm]", "[watt]" };

    while (1)
    {
        measurement.speed = bikeMeasureSpeedInKmh();
        measurement.cadence = bikeMeasureCadenceInRpm();
        measurement.heartRate = bikeMeasureHeartRateInBpm();
        measurement.power = bikeMeasurePowerInWatt();

        bikeStoreAddMeasurement(measurement);

        for (int i = 0; i < 4; i++)
        {
            uint16_t min = bikeMathCalculateMinValue(dataTypes[i]);
            uint16_t max = bikeMathCalculateMaxValue(dataTypes[i]);
            uint16_t avg = bikeMathCalculateAverageValue(dataTypes[i]);

            printf("%s:\t\t%d, average = %d, min = %d, max = %d %s\n",
                   labels[i], bikeMathGetValueForDataType(measurement, dataTypes[i]), avg, min, max, units[i]);
        }
        printf("\n");
        sleep(1);
    }
}
