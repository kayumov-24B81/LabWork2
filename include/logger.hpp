#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP
#include "event.hpp"

/**
    \brief A class that acts as a wrapper for objects of the Event class. 

    This class is responsible for converting individual Event class objects into a complete message about the result of the interaction. Logger gets Event class objects from Interaction Manager and passes formatted log messages to UI Manager
*/

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
