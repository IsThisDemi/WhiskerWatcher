#include "Reader.h"

#include <stdexcept>
#include <QJsonArray>

#include "Sensor/Humidity.h"
#include "Sensor/Light.h"
#include "Sensor/Temperature.h"
#include "Sensor/Wind.h"
#include "Service/Logger/Singleton.h"

namespace Utility {
    namespace Converter {
        namespace Json {
            const std::map<unsigned int, Sensor::AbstractSensor*> &Reader::getCache() const
            {
                return cache;
            }

            Reader& Reader::clear()
            {
                cache.clear();
                return *this;
            }

            Sensor::AbstractSensor *Reader::read(const QJsonObject &object)
            {
                QJsonValue type = object.value("type");
                if (type.isUndefined())
                {
                    Service::Logger::Singleton::get().error("Missing item type.");
                    throw std::invalid_argument("Missing item type.");
                }
                const unsigned int identifier = object.value("id").toInt(); //?
                if (cache.count(identifier) > 0)
                {
                    return cache[identifier];
                }
                else if (type.toString().compare("Humidity") == 0)
                {
                    cache[identifier] = readHumidity(object);
                }
                else if (type.toString().compare("Light") == 0)
                {
                    cache[identifier] = readLight(object);
                }
                else if (type.toString().compare("Temperature") == 0)
                {
                    cache[identifier] = readTemperature(object);
                }
                else if (type.toString().compare("Wind") == 0)
                {
                    cache[identifier] = readWind(object);
                }
                else
                {
                    Service::Logger::Singleton::get().error("Unknown item type.");
                    throw std::invalid_argument("Unknown type.");
                }
                return cache[identifier];
            }

            Sensor::AbstractSensor *Reader::readHumidity(const QJsonObject &object) const
            {
                return new Sensor::Humidity(
                    object.value("id").toInt(),
                    object.value("name").toString().toStdString(),
                    object.value("description").toString().toStdString(),
                    object.value("brand").toString().toStdString(),
                    object.value("humidity").toDouble(),
                    object.value("accuracy").toDouble()
                );
            }

            Sensor::AbstractSensor *Reader::readLight(const QJsonObject &object) const
            {
                return new Sensor::Light(
                    object.value("id").toInt(),
                    object.value("name").toString().toStdString(),
                    object.value("description").toString().toStdString(),
                    object.value("brand").toString().toStdString(),
                    object.value("intensity").toDouble(),
                    object.value("color").toString().toStdString(),
                    object.value("signalStrength").toDouble()
                );
            }

            Sensor::AbstractSensor *Reader::readTemperature(const QJsonObject &object) const
            {
                return new Sensor::Temperature(
                    object.value("id").toInt(),
                    object.value("name").toString().toStdString(),
                    object.value("description").toString().toStdString(),
                    object.value("brand").toString().toStdString(),
                    object.value("temperature").toDouble(),
                    object.value("unit").toString().toStdString(),
                    object.value("accuracy").toDouble()
                );
            }

            Sensor::AbstractSensor *Reader::readWind(const QJsonObject &object) const
            {
                return new Sensor::Wind(
                    object.value("id").toInt(),
                    object.value("name").toString().toStdString(),
                    object.value("description").toString().toStdString(),
                    object.value("brand").toString().toStdString(),
                    object.value("speed").toDouble(),
                    object.value("unit").toString().toStdString(),
                    object.value("direction").toString().toStdString(),
                    object.value("accuracy").toDouble()
                );
            }
        }
    }
}