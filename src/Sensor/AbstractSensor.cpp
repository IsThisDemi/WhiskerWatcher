#include "AbstractSensor.h"

namespace Sensor {
    AbstractSensor::AbstractSensor(
        const unsigned int id, 
        const std::string name, 
        const std::string description, 
        const std::string brand
    ) : id(id), name(name), description(description), brand(brand) {}

    AbstractSensor::~AbstractSensor() {}

    unsigned int AbstractSensor::getId() const {
        return id;
    }

    const std::string AbstractSensor::getName() const {
        return name;
    }

    AbstractSensor& AbstractSensor::setName(const std::string name) {
        this->name = name;
        return *this;
    }

    const std::string AbstractSensor::getDescription() const {
        return description;
    }

    AbstractSensor& AbstractSensor::setDescription(const std::string description) {
        this->description = description;
        return *this;
    }

    const std::string AbstractSensor::getBrand() const {
        return brand;
    }

    AbstractSensor& AbstractSensor::setBrand(const std::string brand) {
        this->brand = brand;
        return *this;
    }
    
}