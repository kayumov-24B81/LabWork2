#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP
#include "event.hpp"

class Logger
{
    private:
        std :: vector<std :: string> logs;
    public:
        Logger();
        void addEvent(const Event& event);
        std :: vector<std :: string> getLogs();
        void resetLogger();
};

#endif
