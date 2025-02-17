# include "utils/scheduled_event.hpp"


void ScheduledEvent::call()
{
    if (this->start + this->seconds <= GetTime())
    {
        this->function();

        if (this->recurring)
        {
            this->start = GetTime();
        }
        else
        {
            this->canceled = true;
        }
    }
}


void ScheduledEvent::cancel()
{
    this->canceled = true;
}


bool ScheduledEvent::is_canceled()
{
    return this->canceled;
}