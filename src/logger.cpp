#include "game.hpp"

Logger :: Logger()
{
    logs.assign(2, "");
}

void Logger :: addEvent(const Event& event)
{
    logs[static_cast<int>(event.getType())] += event.formatMessage();
}

std :: vector<std :: string> Logger :: getLogs()
{
    return logs;
}

void Logger :: resetLogger()
{
    logs.assign(2, "");
}
