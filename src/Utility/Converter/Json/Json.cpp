#include "Json.h"
#include "JsonVisitor.h"

namespace Utility
{
    namespace Converter
    {
        namespace Json
        {

            Json::Json(IReader &_reader) : reader(_reader) {}

            const IReader &Json::getReader() const
            {
                return reader;
            }

            QJsonObject Json::fromObject(const Sensor::AbstractSensor& sensor) const
            {
                JsonVisitor json_visitor;
                sensor.accept(json_visitor);
                return json_visitor.getObject();
            }

            Sensor::AbstractSensor *Json::toObject(const QJsonObject &json) const
            {
                return reader.read(json);
            }

        }
    }
}