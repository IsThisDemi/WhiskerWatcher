#include "SensorBoard.h"

namespace Engine {
    SensorBoard::SensorBoard() : board() {}

    SensorBoard& SensorBoard::addSensor(const Sensor::AbstractSensor* new_sensor) {
        const Sensor::AbstractSensor* old_sensor = nullptr;
        old_sensor = board.checkAdded(new_sensor);
        if (old_sensor != nullptr) {
            board.remove(old_sensor);
        }
        board.add(new_sensor);
        return *this;
    }

    SensorBoard& SensorBoard::removeSensor(const Sensor::AbstractSensor* sensor) {
        board.remove(sensor);
        return *this;
    }

    SensorBoard& SensorBoard::clear() {
        board.clear();
        return *this;
    }
}