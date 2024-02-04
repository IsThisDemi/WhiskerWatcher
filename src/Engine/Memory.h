#ifndef ENGINE_MEMORY_H
#define ENGINE_MEMORY_H

#include "IEngine.h"

#include "../Sensor/AbstractSensor.h"
#include "../Service/Container.h"
#include "Query.h"
#include "ResultSet.h"

namespace Engine {
    class Memory : public IEngine {
        private:
            Service::Container<const Sensor::AbstractSensor*> sensors;
        public:
            Memory();
            virtual ~Memory();
            virtual Memory& add(const Sensor::AbstractSensor* sensor);
            virtual Memory& remove(const Sensor::AbstractSensor* sensor);
            virtual Memory& clear();
            virtual ResultSet search(const Query& query) const;
    };
}

#endif