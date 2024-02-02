#ifndef UTILITY_CONVERTER_JSON_JSON_VISITOR_H
#define UTILITY_CONVERTER_JSON_JSON_VISITOR_H

#include <QJsonObject>
#include "../../../Sensor/IConstVisitor.h"
#include "../../../Sensor/Humidity.h"
#include "../../../Sensor/Light.h"
#include "../../../Sensor/Temperature.h"
#include "../../../Sensor/Wind.h"

namespace Component
{
    namespace Converter
    {
        namespace Json
        {

            class JsonVisitor : public IConstVisitor
            {
            private:
                QJsonObject object;

            public:
                QJsonObject getObject() const;
                void visit(const Humidity &humidity);
                void visit(const Light &light);
                void visit(const Temperature &temperature);
                void visit(const Wind &wind);
            };
        }
    }
}

#endif