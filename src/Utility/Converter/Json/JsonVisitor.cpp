#include "JsonVisitor.h"

namespace Utility
{
    namespace Converter
    {
        namespace Json
        {

            QJsonObject JsonVisitor::getObject() const
            {
                return object;
            }

            void JsonVisitor::visit(const Sensor::Humidity& humidity )
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

            void JsonVisitor::visit(const Sensor::Light &light)
            {
                QJsonObject light_object;
                light_object.insert("type", QJsonValue::fromVariant("Light"));
                light_object.insert("id", QJsonValue::fromVariant(light.getId()));
                light_object.insert("name", QJsonValue::fromVariant(light.getName().c_str()));
                light_object.insert("description", QJsonValue::fromVariant(light.getDescription().c_str()));
                light_object.insert("brand", QJsonValue::fromVariant(light.getBrand().c_str()));
                light_object.insert("intensity", QJsonValue::fromVariant(light.getIntensity()));
                light_object.insert("color", QJsonValue::fromVariant(light.getColor().c_str()));
                light_object.insert("signalStrength", QJsonValue::fromVariant(light.getSignalStrength()));
                object = light_object;
            }

            void JsonVisitor::visit(const Sensor::Temperature &temperature)
            {
                QJsonObject temperature_object;
                temperature_object.insert("type", QJsonValue::fromVariant("Temperature"));
                temperature_object.insert("id", QJsonValue::fromVariant(temperature.getId()));
                temperature_object.insert("name", QJsonValue::fromVariant(temperature.getName().c_str()));
                temperature_object.insert("description", QJsonValue::fromVariant(temperature.getDescription().c_str()));
                temperature_object.insert("brand", QJsonValue::fromVariant(temperature.getBrand().c_str()));
                temperature_object.insert("temperature", QJsonValue::fromVariant(temperature.getTemperature()));
                temperature_object.insert("unit", QJsonValue::fromVariant(temperature.getUnit()));
                temperature_object.insert("accuracy", QJsonValue::fromVariant(temperature.getAccuracy()));
                object = temperature_object;
            }

            void JsonVisitor::visit(const Sensor::Wind &wind)
            {
                QJsonObject wind_object;
                wind_object.insert("type", QJsonValue::fromVariant("Wind"));
                wind_object.insert("id", QJsonValue::fromVariant(wind.getId()));
                wind_object.insert("name", QJsonValue::fromVariant(wind.getName().c_str()));
                wind_object.insert("description", QJsonValue::fromVariant(wind.getDescription().c_str()));
                wind_object.insert("brand", QJsonValue::fromVariant(wind.getBrand().c_str()));
                wind_object.insert("speed", QJsonValue::fromVariant(wind.getSpeed()));
                wind_object.insert("unit", QJsonValue::fromVariant(wind.getUnit()));
                wind_object.insert("direction", QJsonValue::fromVariant(wind.getDirection().c_str()));
                wind_object.insert("accuracy", QJsonValue::fromVariant(wind.getAccuracy()));
                object = wind_object;
            }

        }
    }
}