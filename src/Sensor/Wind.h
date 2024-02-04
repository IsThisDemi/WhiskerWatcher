#ifndef SENSOR_WIND_H
#define SENSOR_WIND_H

#include "AbstractSensor.h"

namespace Sensor {
    class Wind : public AbstractSensor {
        private:
            double speed;
            std::string unit;
            std::string direction;
            double accuracy;

        public:
            Wind(
                const unsigned int id, 
                const std::string name, 
                const std::string description, 
                const std::string brand, 
                const double speed, 
                const std::string unit, 
                const std::string direction, 
                const double accuracy
            );

            double getSpeed() const;
            Wind& setSpeed(const double speed);

            std::string getUnit() const;
            Wind& setUnit(const std::string unit);

            std::string getDirection() const;
            Wind& setDirection(const std::string direction);

            double getAccuracy() const;
            Wind& setAccuracy(const double accuracy);

            virtual void accept(IConstVisitor& visitor) const;
            virtual void accept(IVisitor& visitor);
    };
}

#endif