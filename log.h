#include <iostream>
#include <string>
#include <syncstream>
#define INFO "INFO"
#define DEBUG "DEBUG"
#define WARNING "WARNING"
#define ERROR "ERROR"

class Logger
{
    public:
        Logger(const std::string& s);
        std::osyncstream operator()(const std::string& type);
        Logger & operator = (const Logger &) = delete;
        std::osyncstream operator<<(const std::string& message);
    private:
        std::string prefix;
};

Logger getLogger();
Logger getLogger(const std::string& s);