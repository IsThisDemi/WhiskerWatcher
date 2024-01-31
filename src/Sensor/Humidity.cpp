#include "Humidity.h"

namespace Sensor {
    Humidity::Humidity(
        const unsigned int id, 
        const std::string name, 
        const std::string description, 
        const std::string brand, 
        const double humidity, 
        const double accuracy
    ) : AbstractSensor(id, name, description, brand), humidity(humidity), accuracy(accuracy) {}

    double Humidity::getHumidity() const {
        return humidity;
    }

    Humidity& Humidity::setHumidity(const double humidity) {
        this->humidity = humidity;
        return *this;
    }

    double Humidity::getAccuracy() const {
        return accuracy;
    }

    Humidity& Humidity::setAccuracy(const double accuracy) {
        this->accuracy = accuracy;
        return *this;
    }
}