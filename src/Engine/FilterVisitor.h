#ifndef ENGINE_FILTER_VISITOR_H
#define ENGINE_FILTER_VISITOR_H

#include "Query.h"
#include "../Sensor/IConstVisitor.h"
#include "../Sensor/Humidity.h"
#include "../Sensor/Light.h"
#include "../Sensor/Temperature.h"
#include "../Sensor/Wind.h"

namespace Engine {
    class FilterVisitor : public Sensor::IConstVisitor {
        private:
            const Query& query;
            bool has_match;
        public:
            FilterVisitor(const Query& query);
            const Query& getQuery() const;
            bool hasMatch() const;
            virtual void visit(const Sensor::Humidity& sensor);
            virtual void visit(const Sensor::Light& sensor);
            virtual void visit(const Sensor::Temperature& sensor);
            virtual void visit(const Sensor::Wind& sensor);
    };
}

#endif