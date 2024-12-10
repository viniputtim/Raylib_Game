# ifndef SCHEDULED_EVENT_HPP
# define SCHEDULED_EVENT_HPP


# include <raylib.h>
# include <functional>
# include <utility>


class ScheduledEvent
{
    public:
        bool was_canceled;

        template<typename F, typename... Args>
        ScheduledEvent(bool repeat, double seconds, F function, Args... args)
        {
            this->repeat = repeat;
            this->start_time = GetTime();
            this->delay = seconds;
            this->callback = [func = std::forward<F> (function),
                ...args = std::forward<Args> (args)]() {func(args...);};
        }

        ~ScheduledEvent();
        void call();
        void cancel();

    private:
        bool repeat;
        double start_time;
        double delay;
        std::function<void()> callback;
};

# endif