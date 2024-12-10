# include "utils/scheduled_event.hpp"


ScheduledEvent::~ScheduledEvent()
{

}


void ScheduledEvent::call()
{
    if (this->start_time + delay <= GetTime())
    {
        this->callback();

        if (this->repeat)
        {
            this->start_time = GetTime();
        }
        else
        {
            this->was_canceled = true;
        }
    }
}