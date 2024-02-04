#ifndef SENSOR_TEMPERATURE_H
#define SENSOR_TEMPERATURE_H

#include "AbstractSensor.h"

namespace Sensor {
    class Temperature : public AbstractSensor {
        private:
            double temperature;
            std::string unit; 
            double accuracy;

        public:
            Temperature(
                const unsigned int id, 
                const std::string name, 
                const std::string description, 
                const std::string brand, 
                const double temperature, 
                const std::string unit, 
                const double accuracy
            );

            double getTemperature() const;
            Temperature& setTemperature(const double temperature);

            std::string getUnit() const;
            Temperature& setUnit(const std::string unit);

            double getAccuracy() const;
            Temperature& setAccuracy(const double accuracy);

            virtual void accept(IConstVisitor& visitor) const;
            virtual void accept(IVisitor& visitor);
    };
}

#endif