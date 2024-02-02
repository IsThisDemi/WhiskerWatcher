#include "Query.h"

namespace Engine {
    Query::Query(const unsigned int t) : type(t) {}

    unsigned int Query::getType() const {
        return type;
    }
}