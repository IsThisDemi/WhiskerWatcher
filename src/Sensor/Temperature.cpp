#include "Temperature.h"

namespace Sensor{
    Temperature::Temperature(
        const unsigned int id, 
        const std::string name, 
        const std::string description, 
        const std::string brand, 
        const double temperature, 
        const char unit, 
        const double accuracy
    ) : AbstractSensor(id, name, description, brand), temperature(temperature), unit(unit), accuracy(accuracy) {}

    double Temperature::getTemperature() const {
        return temperature;
    }

    Temperature& Temperature::setTemperature(const double temperature) {
        this->temperature = temperature;
        return *this;
    }

    char Temperature::getUnit() const {
        return unit;
    }

    Temperature& Temperature::setUnit(const char unit) {
        this->unit = unit;
        return *this;
    }

    double Temperature::getAccuracy() const {
        return accuracy;
    }

    Temperature& Temperature::setAccuracy(const double accuracy) {
        this->accuracy = accuracy;
        return *this;
    }

    void Temperature::accept(IConstVisitor& visitor) const {
        visitor.visit(*this);
    }

    void Temperature::accept(IVisitor& visitor) {
        visitor.visit(*this);
    }
}