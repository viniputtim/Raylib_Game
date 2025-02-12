# ifndef SCHEDULED_EVENT_HPP
# define SCHEDULED_EVENT_HPP


# include <raylib.h>
# include <functional>


class ScheduledEvent
{
    private:
        double start;
        double seconds;
        std::function<void()> function;
        bool recurring;
        bool canceled = false;

    public:
        template<typename Function, typename... Args>
        ScheduledEvent(Function function, double seconds, bool recurring, Args... args)
        {
            this->function = [func = std::forward<Function> (function),
                ...args =std::forward<Args> (args)]() {func(args...);};
            this->seconds = seconds;
            this->recurring = recurring;
            this->start = GetTime();
        }
        ~ScheduledEvent();

        void call();
        void cancel();
        bool is_canceled();
};

# endif