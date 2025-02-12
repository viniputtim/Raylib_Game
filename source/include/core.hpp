# ifndef CORE_HPP
# define CORE_HPP


# include <raylib.h>
# include <functional>
# include <map>
# include <memory>
# include <string>
# include <vector>
# include "utils/scheduled_event.hpp"
# include "scenes/scene.hpp"
# include "scenes/loading.hpp"


class Core
{
    private:
        std::vector<std::shared_ptr<ScheduledEvent>> scheduled_events;
        std::map<std::string, std::function<void()>> scenes;
        std::unique_ptr<Scene> scene;

        void change_scene(std::string scene_name);
        void check_scheduled_events();
        void check_events();
        void update();
        void draw();

        template<typename Function, typename... Args>
        std::shared_ptr<ScheduledEvent> schedule_event(
            Function function, double seconds, bool recurring, Args... args
        )
        {
            std::shared_ptr<ScheduledEvent> scheduled_event =
                std::make_shared<ScheduledEvent> (function, seconds, recurring, args...);

            this->scheduled_events.push_back(scheduled_event);
            return scheduled_event;
        }

    public:
        Core();
        ~Core();

        void run();

        template<typename Function, typename... Args>
        std::shared_ptr<ScheduledEvent> schedule_once(
            Function function, double seconds, Args... args
        )
        {
           return schedule_event(function, seconds, false, args...);
        }

        template<typename Function, typename... Args>
        std::shared_ptr<ScheduledEvent> schedule_interval(
            Function function, double seconds, Args... args
        )
        {
           return schedule_event(function, seconds, true, args...);
        }
};

# endif