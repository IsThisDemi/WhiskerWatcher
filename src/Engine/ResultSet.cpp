#include <algorithm>

#include "ResultSet.h"
#include "../Sensor/AbstractSensor.h"

namespace Engine
{
    ResultSet::ResultSet(const unsigned int s) : size(s) {}

    unsigned int ResultSet::getSize() const {
        return size;
    }

    const std::vector<SensorShown>& ResultSet::getShownSensors() const {
        return shownSensors;
    }

    ResultSet& ResultSet::add(const SensorShown sensor) {
        shownSensors.push_back(sensor);
        return *this;
    }
}