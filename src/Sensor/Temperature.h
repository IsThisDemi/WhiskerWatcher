#ifndef SENSOR_TEMPERATURE_H
#define SENSOR_TEMPERATURE_H

#include "AbstractSensor.h"

namespace Sensor {
    class Temperature : public AbstractSensor {
        private:
            double temperature;
            char unit; 
            double accuracy;

        public:
            Temperature(const unsigned int id, std::string name, std::string description, std::string brand, double temperature, char unit, double accuracy);

            double getTemperature() const;
            Temperature& setTemperature(const double temperature);

            char getUnit() const;
            Temperature& setUnit(const char unit);

            double getAccuracy() const;
            Temperature& setAccuracy(const double accuracy);

            void accept(IConstVisitor& visitor) const override;
            void accept(IVisitor& visitor) override;
    };
}

#endif