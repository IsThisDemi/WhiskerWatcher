#include "Wind.h"

namespace Sensor {
    Wind::Wind(
        const unsigned int id, 
        const std::string name, 
        const std::string description, 
        const std::string brand, 
        const double speed, 
        const std::string unit, 
        const std::string direction, 
        const double accuracy
    ) : AbstractSensor(id, name, description, brand), speed(speed), unit(unit), direction(direction), accuracy(accuracy) {}

    double Wind::getSpeed() const {
        return speed;
    }

    Wind& Wind::setSpeed(const double speed) {
        this->speed = speed;
        return *this;
    }

    std::string Wind::getUnit() const {
        return unit;
    }

    Wind& Wind::setUnit(const std::string unit) {
        this->unit = unit;
        return *this;
    }

    std::string Wind::getDirection() const {
        return direction;
    }

    Wind& Wind::setDirection(const std::string direction) {
        this->direction = direction;
        return *this;
    }

    double Wind::getAccuracy() const {
        return accuracy;
    }

    Wind& Wind::setAccuracy(const double accuracy) {
        this->accuracy = accuracy;
        return *this;
    }

    void Wind::accept(IConstVisitor& visitor) const {
        visitor.visit(*this);
    }

    void Wind::accept(IVisitor& visitor) {
        visitor.visit(*this);
    }
}