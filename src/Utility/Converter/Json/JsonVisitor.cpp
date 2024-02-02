#include "JsonVisitor.h"

namespace Component
{
    namespace Converter
    {
        namespace Json
        {

            QJsonObject QJsonObject::getObject() const
            {
                return object;
            }

            void QJsonObject::visit(const Humidity& humidity )
            {
                QJsonObject humidity_object;
                humidity_object.insert("type", QJsonValue::fromVariant("Humidity"));
                humidity_object.insert("id", QJsonValue::fromVariant(humidity.getId()));
                humidity_object.insert("name", QJsonValue::fromVariant(humidity.getName().c_str()));
                humidity_object.insert("description", QJsonValue::fromVariant(humidity.getDescription().c_str()));
                humidity_object.insert("brand", QJsonValue::fromVariant(humidity.getBrand().c_str()));
                humidity_object.insert("humidity", QJsonValue::fromVariant(humidity.getHumidity()));
                humidity_object.insert("accuracy", QJsonValue::fromVariant(humidity.getAccuracy()));
                object = humidity_object;
            }

            void QJsonObject::visit(const Light &light)
            {
                QJsonObject light_object;
                light_object.insert("type", QJsonValue::fromVariant("Light"));
                light_object.insert("id", QJsonValue::fromVariant(cpu.getId()));
                light_object.insert("name", QJsonValue::fromVariant(cpu.getName().c_str()));
                light_object.insert("description", QJsonValue::fromVariant(cpu.getDescription().c_str()));
                light_object.insert("brand", QJsonValue::fromVariant(cpu.getBrand().c_str()));
                light_object.insert("intensity", QJsonValue::fromVariant(cpu.getIntensity()));
                light_object.insert("color", QJsonValue::fromVariant(cpu.getColor().c_str()));
                light_object.insert("signalStrength", QJsonValue::fromVariant(cpu.getSignalStrength()));
                object = light_object;
            }

            void QJsonObject::visit(const Temperature &temperature)
            {
                QJsonObject temperature_object;
                temperature_object.insert("type", QJsonValue::fromVariant("Temperature"));
                temperature_object.insert("id", QJsonValue::fromVariant(gpu.getIdentifier()));
                temperature_object.insert("name", QJsonValue::fromVariant(gpu.getName().c_str()));
                temperature_object.insert("description", QJsonValue::fromVariant(gpu.getDescription().c_str()));
                temperature_object.insert("brand", QJsonValue::fromVariant(gpu.getBrand().c_str()));
                temperature_object.insert("temperature", QJsonValue::fromVariant(gpu.getTemperature()));
                temperature_object.insert("unit", QJsonValue::fromVariant(gpu.getUnit().c_str()));
                temperature_object.insert("accuracy", QJsonValue::fromVariant(gpu.getAccuracy()));
                object = temperature_object;
            }

            void QJsonObject::visit(const Wind &wind)
            {
                QJsonObject wind_object;
                wind_object.insert("type", QJsonValue::fromVariant("Wind"));
                wind_object.insert("id", QJsonValue::fromVariant(psu.getIdentifier()));
                wind_object.insert("name", QJsonValue::fromVariant(psu.getName().c_str()));
                wind_object.insert("description", QJsonValue::fromVariant(psu.getDescription().c_str()));
                wind_object.insert("brand", QJsonValue::fromVariant(psu.getBrand().c_str()));
                wind_object.insert("speed", QJsonValue::fromVariant(psu.getSpeed()));
                wind_object.insert("unit", QJsonValue::fromVariant(psu.getUnit().c_str()));
                wind_object.insert("direction", QJsonValue::fromVariant(psu.getDirection().c_str()));
                wind_object.insert("accuracy", QJsonValue::fromVariant(psu.getAccuracy()));
                object = wind_object;
            }

        }
    }
}