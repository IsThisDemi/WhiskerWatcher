#ifndef ENGINE_RESULT_SET_H
#define ENGINE_RESULT_SET_H 

#include <vector>

#include "SensorShown.h"

namespace Engine {
    class ResultSet {
        private:
            const unsigned int size;
            std::vector<SensorShown> shownSensors;
        public:
            ResultSet(const unsigned int s);
            unsigned int getSize() const;
            const std::vector<SensorShown>& getShownSensors() const;
            ResultSet& add(const SensorShown sensor);
    };
}
#endif