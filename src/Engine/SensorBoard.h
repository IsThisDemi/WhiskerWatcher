#ifndef ENGINE_SENSOR_BOARD_H
#define ENGINE_SENSOR_BOARD_H

#include "../Service/Container.h"
#include "../Sensor/AbstractSensor.h"

namespace Engine {
    class SensorBoard {
        private:
            Service::Container<const Sensor::AbstractSensor*> board;
        public:
            SensorBoard();
            ~SensorBoard() = default;

            SensorBoard& addSensor(const Sensor::AbstractSensor* sensor);
            SensorBoard& removeSensor(const Sensor::AbstractSensor* sensor);
            SensorBoard& clear();
    };
}

#endif