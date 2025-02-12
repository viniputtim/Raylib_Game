# include "core.hpp"


Core::Core()
{
    this->scenes["loading"] = [this]() {this->scene = std::make_unique<Loading> ();};

    this->change_scene("loading");
}


Core::~Core()
{

}


void Core::change_scene(std::string scene_name)
{
    this->scenes[scene_name]();
}


void Core::run()
{
    while (!WindowShouldClose())
    {
        this->check_scheduled_events();
        this->check_events();
        this->update();
        this->draw();
    }
}


void Core::check_scheduled_events()
{
    for (auto it = this->scheduled_events.begin(); it != this->scheduled_events.end();)
    {
        std::shared_ptr<ScheduledEvent> event = *it;

        if (event->is_canceled())
        {
            it = this->scheduled_events.erase(it);
        }
        else
        {
            event->call();
            ++it;
        }
    }
}


void Core::check_events()
{
    this->scene->check_events();
}


void Core::update()
{
    this->scene->update();
}


void Core::draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    this->scene->draw();
    DrawFPS(0, 0);
    EndDrawing();
}