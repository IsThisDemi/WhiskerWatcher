#include "JsonRepository.h"

#include <stdexcept>

#include "../Converter/Json/Json.h"
#include "../Converter/Json/Reader.h"

namespace Utility {
    namespace Repository {
        JsonRepository::JsonRepository(DataMapper::JsonFile data_mapper) : data_mapper(data_mapper) {
            std::vector<Sensor::AbstractSensor*> sensors(data_mapper.load());
            for (
                std::vector<Sensor::AbstractSensor*>::const_iterator it = sensors.begin();
                it != sensors.end();
                it++)
            {
                repository[(*it)->getId()] = *it;
            }
        }

        JsonRepository::~JsonRepository()
        {
            for(
                std::map<unsigned int, Sensor::AbstractSensor*>::const_iterator it = repository.begin();
                it != repository.end();
                it++)
            {
                delete it->second;
            }
        }

        JsonRepository JsonRepository::fromPath(const std::string path)
        {
            Converter::Json::Reader reader;
            Converter::Json::Json converter(reader);
            DataMapper::JsonFile data_mapper(path, converter);
            JsonRepository repository(data_mapper);
            return repository;
        }

        const DataMapper::JsonFile& JsonRepository::getDataMapper() const
        {
            return data_mapper;
        }

        const std::map<unsigned int, Sensor::AbstractSensor*>& JsonRepository::getRepository() const
        {
            return repository;
        }

        const std::string& JsonRepository::getPath() const
        {
            return data_mapper.getPath();
        }

        JsonRepository& JsonRepository::setPath(std::string path)
        {
            data_mapper.setPath(path);
            return *this;
        }

        JsonRepository& JsonRepository::create(Sensor::AbstractSensor* sensor)
        {
            repository[sensor->getId()] = sensor;
            return *this;
        }

        Sensor::AbstractSensor* JsonRepository::read(const unsigned int id) const
        {
            std::map<unsigned int, Sensor::AbstractSensor*>::const_iterator it = repository.find(id);
            if (it == repository.end())
            {
                throw std::invalid_argument("Undefined it, sensor not found");
            }
            return it->second;
        }

        JsonRepository& JsonRepository::update(Sensor::AbstractSensor* sensor)
        {
            return create(sensor);
        }

        JsonRepository& JsonRepository::remove(const unsigned int id)
        {
            std::map<unsigned int, Sensor::AbstractSensor*>::const_iterator it = repository.find(id);
            if (it != repository.end())
            {
                delete it->second;
                repository.erase(it);
            }
            return *this;
        }

        std::vector<Sensor::AbstractSensor*> JsonRepository::readAll() const
        {
            std::vector<Sensor::AbstractSensor*> sensors;
            for (
                std::map<unsigned int, Sensor::AbstractSensor*>::const_iterator it = repository.begin();
                it != repository.end();
                it++)
            {
                sensors.push_back(it->second);
            }
            return sensors;
        }

        JsonRepository& JsonRepository::store()
        {
            data_mapper.store(readAll());
            return *this;
        }
    }
}