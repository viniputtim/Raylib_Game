# ifndef SCHEDULED_EVENT_HPP
# define SCHEDULED_EVENT_HPP


# include <raylib.h>
# include <functional>


class ScheduledEvent
{
    private:
        double start {0};
        double seconds {0};
        std::function<void()> function {[]() {}};
        bool recurring {false};
        bool canceled {false};

    public:
        template<typename Function, typename... Args>
        ScheduledEvent(Function function, double seconds, bool recurring, Args... args) :
            function(
                [func = std::forward<Function> (function),
                ...args = std::forward<Args> (args)]() {func(args...);}
            ),
            seconds(seconds),
            recurring(recurring),
            start(GetTime())
        {}

        void call();
        void cancel();
        bool is_canceled();
};

# endif