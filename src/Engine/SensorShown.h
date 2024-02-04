#ifndef ENGINE_SENSORSHOWN_H
#define ENGINE_SENSORSHOWN_H

#include "../Sensor/AbstractSensor.h"

namespace Engine {
    class SensorShown {
        private:
            const Sensor::AbstractSensor* sensor;
        public:
            SensorShown(const Sensor::AbstractSensor* sens);
            const Sensor::AbstractSensor* getSensor() const;
    };
}

#endif