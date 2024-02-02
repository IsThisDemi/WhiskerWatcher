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
                    std::map<unsigned int, AbstractComponent*> &getCache() const;
                    Reader& clear();
                    virtual AbstractComponent* read(const QJsonObject& object);
                public:
                    AbstractComponent* readHumidity(const QJsonObject& object) const;
                    AbstractComponent* readLight(const QJsonObject& object) const;
                    AbstractComponent* readTemperature(const QJsonObject& object) const;
                    AbstractComponent* readWind(const QJsonObject& object) const;
            };
        }
    }
}

#endif