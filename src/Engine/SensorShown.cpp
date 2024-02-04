#include "SensorShown.h"

namespace Engine {
    SensorShown::SensorShown(const Sensor::AbstractSensor* sens) : sensor(sens) {}

    const Sensor::AbstractSensor* SensorShown::getSensor() const {
        return sensor;
    }
}