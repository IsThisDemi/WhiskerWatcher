#ifndef SENSOR_ABSTRACTSENSOR_H
#define SENSOR_ABSTRACTSENSOR_H

#include <string>

#include "IConstVisitor.h"
#include "IVisitor.h"

namespace Sensor{
    class AbstractSensor {
        private:
            const unsigned int id;
            std::string name;
            std::string description;
            std::string brand;
        
        protected:
            AbstractSensor(
                const unsigned int id, 
                const std::string name, 
                const std::string description, 
                const std::string brand
            );
        
        public:
            virtual ~AbstractSensor();
            unsigned int getId() const;
            const std::string getName() const;
            AbstractSensor& setName(const std::string name);
            const std::string getDescription() const;
            AbstractSensor& setDescription(const std::string description);
            const std::string getBrand() const;
            AbstractSensor& setBrand(const std::string brand);

            virtual void accept(IConstVisitor& visitor) const = 0;
            virtual void accept(IVisitor& visitor) = 0;
    };
}

#endif