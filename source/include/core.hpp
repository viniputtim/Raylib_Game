# ifndef CORE_HPP
# define CORE_HPP

# include <raylib.h>
# include <functional>
# include <vector>
# include <map>
# include <string>
# include "utils/scheduled_event.hpp"
# include "utils/resource_manager.hpp"
# include "scenes/scene.hpp"
# include "scenes/main_menu.hpp"


class Core
{
    public:
        ResourceManager resource_manager;

        Core();
        ~Core();
        void run();
        void change_scene(std::string scene_name);

        template<typename F, typename... Args>
        ScheduledEvent set_timeout(double seconds, F function, Args... args)
        {
            ScheduledEvent event = ScheduledEvent(false, seconds, function, args...);
            this->scheduled_events.push_back(event);

            return event;
        }

        template<typename F, typename... Args>
        ScheduledEvent set_interval(double seconds, F function, Args... args)
        {
            ScheduledEvent event = ScheduledEvent(true, seconds, function, args...);
            this->scheduled_events.push_back(event);

            return event;
        }

    private:
        std::vector<ScheduledEvent> scheduled_events;
        Scene* current_scene;
        std::map<std::string, std::function<void()>> scenes;

        void check_scheduled_events();
        void check_events();
        void update();
        void draw();
};

# endif