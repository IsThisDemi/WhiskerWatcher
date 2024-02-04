#ifndef UTILITY_CONVERTER_JSON_JSON_H
#define UTILITY_CONVERTER_JSON_JSON_H

#include <QJsonObject>
#include "../../../Sensor/AbstractSensor.h"
#include "IReader.h"

namespace Utility {
    namespace Converter {
        namespace Json {
            class Json {
                private:
                    IReader& reader;
                public:
                    Json(IReader& _reader);
                    const IReader& getReader() const;
                    QJsonObject fromObject(const Sensor::AbstractSensor& sensor) const;
                    Sensor::AbstractSensor* toObject(const QJsonObject& json) const;
            };
        }
    }
}

#endif