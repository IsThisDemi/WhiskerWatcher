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
            Temperature(
                const unsigned int id, 
                const std::string name, 
                const std::string description, 
                const std::string brand, 
                const double temperature, 
                const char unit, 
                const double accuracy
            );

            double getTemperature() const;
            Temperature& setTemperature(const double temperature);

            char getUnit() const;
            Temperature& setUnit(const char unit);

            double getAccuracy() const;
            Temperature& setAccuracy(const double accuracy);

            virtual void accept(IConstVisitor& visitor) const;
            virtual void accept(IVisitor& visitor);
    };
}

#endif