# include "scenes/loading.hpp"


Loading::Loading()
{

}


Loading::Loading(Core* core) : Scene(core)
{

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
}