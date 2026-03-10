#include "log.h"
#include <ctime>
#include <iomanip>
#include <thread>

using namespace std;

Logger::Logger(const std::string& str)
{
    prefix = str;
}

std::osyncstream Logger::operator<<(const std::string& message)
{
        return (Logger::operator()(INFO)) << message;
}

std::osyncstream Logger::operator()(const std::string& type) {
    std::osyncstream syncStream = std::osyncstream(std::cout);
    if (type == DEBUG || type == INFO || type == ERROR || type == WARNING)
    {
            std::time_t currentTime = std::time(nullptr);
            std::tm* localTime = std::localtime(&currentTime);
            syncStream << endl << std::put_time(localTime, "%F %T") << "; ";
            std::thread::id this_id = std::this_thread::get_id();
            syncStream << type <<"; "<< prefix<< "(" << this_id << ")"<<"; ";
    }
    return syncStream;
}

Logger getLogger()
{
    return Logger("");
}

Logger getLogger(const std::string& s)
{
    return Logger(s);
}