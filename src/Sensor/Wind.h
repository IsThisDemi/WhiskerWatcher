#ifndef SENSOR_WIND_H
#define SENSOR_WIND_H

#include "AbstractSensor.h"

namespace Sensor {
    class Wind : public AbstractSensor {
        private:
            double speed;
            char unit;
            std::string direction;
            double accuracy;

        public:
            Wind(
                const unsigned int id, 
                const std::string name, 
                const std::string description, 
                const std::string brand, 
                const double speed, 
                const char unit, 
                const std::string direction, 
                const double accuracy
            );

            double getSpeed() const;
            Wind& setSpeed(const double speed);

            char getUnit() const;
            Wind& setUnit(const char unit);

            std::string getDirection() const;
            Wind& setDirection(const std::string direction);

            double getAccuracy() const;
            Wind& setAccuracy(const double accuracy);

            void accept(IConstVisitor& visitor) const override;
            void accept(IVisitor& visitor) override;
    };
}

#endif