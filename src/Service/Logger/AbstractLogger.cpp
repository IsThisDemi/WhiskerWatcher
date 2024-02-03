#include "AbstractLogger.h"

namespace Service {
    namespace Logger {
        AbstractLogger::~AbstractLogger(){}
        
        const AbstractLogger &AbstractLogger::debug(const std::string &message) const
        {
            return log(message, Level::DEBUG);
        }

        const AbstractLogger &AbstractLogger::error(const std::string &message) const
        {
            return log(message, Level::ERROR);
        }

        const AbstractLogger &AbstractLogger::info(const std::string &message) const
        {
            return log(message, Level::INFO);
        }

        const AbstractLogger &AbstractLogger::warning(const std::string &message) const
        {
            return log(message, Level::WARNING);
        }
    }
}