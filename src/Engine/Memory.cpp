#include "Memory.h"
#include "SensorShown.h"
#include "FilterVisitor.h"

namespace Engine {
    Memory::Memory(){}
    Memory::~Memory() {}

    Memory& Memory::add(const Sensor::AbstractSensor* sensor) {
        sensors.add(sensor);
        return *this;
    }

    Memory& Memory::remove(const Sensor::AbstractSensor* sensor) {
        sensors.remove(sensor);
        return *this;
    }

    Memory& Memory::clear() {
        sensors.clear();
        return *this;
    }

    ResultSet Memory::search(const Query& query) const {
        FilterVisitor filterV(query);
        std::vector<SensorShown> foundSensors;

        for(
            Service::Container<const Sensor::AbstractSensor*>::Node* node = sensors.getHead();
            node != nullptr;
            node = node->getNext()){
                node->getData()->accept(filterV);
                if (filterV.hasMatch()){
                    foundSensors.push_back(SensorShown(node->getData()));
                }
        }

        ResultSet shownSensors(foundSensors.size());
        for(auto it = foundSensors.begin(); it != foundSensors.end(); it++){
            if (foundSensors.size() <= 1)
                shownSensors.add(*it);
            shownSensors.add(*it);
        }

        return shownSensors;
    }
}