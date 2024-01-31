#include "Light.h"

namespace Sensor {
    Light::Light(
        const unsigned int id, 
        const std::string name, 
        const std::string description, 
        const std::string brand, 
        const double intensity, 
        const std::string color, 
        const double signalStrength
    ) : AbstractSensor(id, name, description, brand), intensity(intensity), color(color), signalStrength(signalStrength) {}

    double Light::getIntensity() const {
        return intensity;
    }

    Light& Light::setIntensity(const double intensity) {
        this->intensity = intensity;
        return *this;
    }

    std::string Light::getColor() const {
        return color;
    }

    Light& Light::setColor(const std::string color) {
        this->color = color;
        return *this;
    }

    double Light::getSignalStrength() const {
        return signalStrength;
    }

    Light& Light::setSignalStrength(const double signalStrength) {
        this->signalStrength = signalStrength;
        return *this;
    }
}