#ifndef UTILITY_REPOSITORY_IREPOSITORY_H
#define UTILITY_REPOSITORY_IREPOSITORY_H

#include <vector>
#include "../../Sensor/AbstractSensor.h"

namespace Utility {
    namespace Repository {
        class IRepository {
            public:
                virtual ~IRepository() = default;
                virtual IRepository& create(Sensor::AbstractSensor* sensor) = 0;
                virtual Sensor::AbstractSensor* read(const unsigned int id) const = 0;
                virtual IRepository& update(Sensor::AbstractSensor* sensor) = 0;
                virtual IRepository& remove(const unsigned int id) = 0;
                virtual std::vector<Sensor::AbstractSensor*> readAll() const = 0;
        };
    }
}

#endif