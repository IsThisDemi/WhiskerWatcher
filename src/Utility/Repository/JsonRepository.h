#ifndef UTILITY_REPOSITORY_JSON_REPOSITORY_H
#define UTILITY_REPOSITORY_JSON_REPOSITORY_H

#include <map>
#include <string>

#include "IRepository.h"
#include "../DataMapper/JsonFile.h"

namespace Utility {
    namespace Repository {
        class JsonRepository : public IRepository {
            private:
                Utility::DataMapper::JsonFile data_mapper;
                std::map<unsigned int, Sensor::AbstractSensor*> repository;
            public:
                JsonRepository(Utility::DataMapper::JsonFile data_mapper);
                virtual ~JsonRepository();

                static JsonRepository fromPath(const std::string path);
                const DataMapper::JsonFile& getDataMapper() const;
                const std::map<unsigned int, Sensor::AbstractSensor*>& getRepository() const;
                const std::string& getPath() const;
                JsonRepository& setPath(std::string path);
                virtual JsonRepository& create(Sensor::AbstractSensor* sensor);
                virtual Sensor::AbstractSensor* read(const unsigned int id) const;
                virtual JsonRepository& update(Sensor::AbstractSensor* sensor);
                virtual JsonRepository& remove(const unsigned int id);
                virtual std::vector<Sensor::AbstractSensor*> readAll() const;
                virtual JsonRepository& overwrite(const std::vector<Sensor::AbstractSensor*> &sensors);
                JsonRepository& store();
                JsonRepository& load();
        };
    }
}
#endif