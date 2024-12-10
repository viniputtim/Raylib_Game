# include "core.hpp"


Core::Core()
{
    this->scenes["main menu"] = [this]() {this->current_scene = new MainMenu(this);};

    this->change_scene("main menu");
}


Core::~Core()
{

}


void Core::change_scene(std::string scene_name)
{
    delete this->current_scene;
    this->scenes[scene_name]();
}


void Core::run()
{
    while(!WindowShouldClose())
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
    ScheduledEvent& event = *it;

    if (event.was_canceled)
    {
        it = this->scheduled_events.erase(it);
    }
    else
    {
        event.call();
        ++it;
    }
}
}


void Core::check_events()
{
    this->current_scene->check_events();
}


void Core::update()
{
    this->current_scene->update();
}


void Core::draw()
{
    BeginDrawing();
    this->current_scene->draw();
    DrawFPS(0, 0);
    EndDrawing();
}