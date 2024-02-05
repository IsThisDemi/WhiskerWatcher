QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Utility/Converter/Json/Json.cpp\
    Utility/Converter/Json/JsonVisitor.cpp\
    Utility/Converter/Json/Reader.cpp\
    \
    Utility/DataMapper/JsonFile.cpp\
    \
    Utility/Repository/JsonRepository.cpp\
    \
    Sensor/AbstractSensor.cpp\
    Sensor/Humidity.cpp\
    Sensor/Light.cpp\
    Sensor/Temperature.cpp\
    Sensor/Wind.cpp\
    \
    Engine/SensorShown.cpp\
    Engine/FilterVisitor.cpp\
    Engine/Memory.cpp\
    Engine/Query.cpp\
    Engine/ResultSet.cpp\
    \
    Service/Logger/AbstractLogger.cpp\
    Service/Logger/Singleton.cpp\
    \
    main.cpp \
    \
    View/MainWindow.cpp

HEADERS += \
    Utility/Converter/Json/IReader.h\
    Utility/Converter/Json/Json.h\
    Utility/Converter/Json/JsonVisitor.h\
    Utility/Converter/Json/Reader.h\
    \
    Utility/DataMapper/JsonFile.h\
    \
    Utility/Repository/IRepository.h\
    Utility/Repository/JsonRepository.h\
    \
    Sensor/AbstractSensor.h\
    Sensor/Humidity.h\
    Sensor/Light.h\
    Sensor/Temperature.h\
    Sensor/Wind.h\
    Sensor/IConstVisitor.h\
    Sensor/IVisitor.h\
    \
    Engine/SensorShown.h\
    Engine/FilterVisitor.h\
    Engine/IEngine.h\
    Engine/Memory.h\
    Engine/Query.h\
    Engine/ResultSet.h\
    \
    Service/Logger/Level.h\
    Service/Logger/AbstractLogger.h\
    Service/Logger/Singleton.h\
    \
    Service/Container.h\
    \
    View/MainWindow.h

FORMS += \
    View/mainwindow.ui

RESOURCES += \
    resources.qrc

TRANSLATIONS += \
    WhiskerWatcher_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

target = WhiskerWatcher
