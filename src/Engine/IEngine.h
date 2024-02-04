#ifndef ENGINE_I_ENGINE_H
#define ENGINE_I_ENGINE_H

#include "ResultSet.h"
#include "Query.h"

namespace Engine {
    class IEngine {
        public:
            virtual ~IEngine() = default;
            virtual IEngine& add(const Sensor::AbstractSensor* sensor) = 0;
            virtual IEngine& remove(const Sensor::AbstractSensor* sensor) = 0;
            virtual IEngine& clear() = 0;
            virtual ResultSet search(const Query& query) const = 0;
    };
}

#endif