#include "FilterVisitor.h"

namespace Engine {
    FilterVisitor::FilterVisitor(const Query& query) : query(query), has_match(false) {}

    const Query& FilterVisitor::getQuery() const {
        return query;
    }

    bool FilterVisitor::hasMatch() const {
        return has_match;
    }

    void FilterVisitor::visit(const Sensor::Humidity& sensor) {
        if (query.getType() == 1) {
            has_match = true;
        }
    }

    void FilterVisitor::visit(const Sensor::Light& sensor) {
        if (query.getType() == 2) {
            has_match = true;
        }
    }

    void FilterVisitor::visit(const Sensor::Temperature& sensor) {
        if (query.getType() == 3) {
            has_match = true;
        }
    }

    void FilterVisitor::visit(const Sensor::Wind& sensor) {
        if (query.getType() == 4) {
            has_match = true;
        }
    }

}
