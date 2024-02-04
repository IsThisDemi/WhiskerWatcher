#ifndef UTILITY_CONVERTER_JSON_READER_H
#define UTILITY_CONVERTER_JSON_READER_H

#include <map>
#include <QJsonObject>

#include "IReader.h"

namespace Utility {
    namespace Converter {
        namespace Json {
            class Reader : public IReader {
                private:
                    std::map<unsigned int, Sensor::AbstractSensor*> cache;

                public:
                    const std::map<unsigned int, Sensor::AbstractSensor*> &getCache() const;
                    Reader& clear();
                    virtual Sensor::AbstractSensor* read(const QJsonObject& object);
                    
                private:
                    Sensor::AbstractSensor* readHumidity(const QJsonObject& object) const;
                    Sensor::AbstractSensor* readLight(const QJsonObject& object) const;
                    Sensor::AbstractSensor* readTemperature(const QJsonObject& object) const;
                    Sensor::AbstractSensor* readWind(const QJsonObject& object) const;
            };
        }
    }
}

#endif