#ifndef SENSOR_LIGHT_H
#define SENSOR_LIGHT_H

#include "AbstractSensor.h"

namespace Sensor {
    class Light : public AbstractSensor {
        private:
            double intensity;
            std::string color;
            double signalStrength;

        public:
            Light(
                const unsigned int id, 
                const std::string name, 
                const std::string description, 
                const std::string brand, 
                const double intensity, 
                const std::string color, 
                const double signalStrength
            );

            double getIntensity() const;
            Light& setIntensity(const double intensity);

            std::string getColor() const;
            Light& setColor(const std::string color);

            double getSignalStrength() const;
            Light& setSignalStrength(const double signalStrength);

            virtual void accept(IConstVisitor& visitor) const;
            virtual void accept(IVisitor& visitor);
    };
}

#endif