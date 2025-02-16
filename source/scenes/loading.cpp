# include "scenes/loading.hpp"


Loading::Loading()
{

}


Loading::Loading(Core* core) : Scene(core)
{
    this->raylib = std::make_unique<Surf> ("raylib.png", WHITE);
}


Loading::~Loading()
{

}


void Loading::check_events()
{
    if (IsMouseButtonReleased(0))
    {
        this->core->change_scene("main menu");
    }
}


void Loading::update()
{

}


void Loading::draw()
{
    ClearBackground(GREEN);
    this->raylib->draw();
}