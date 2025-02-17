# include "scenes/loading.hpp"


Loading::Loading()
{

}


Loading::Loading(Core* core) : Scene(core)
{
    this->raylib = std::make_unique<Surf> ("raylib.png", WHITE);
    this->raylib->get_rect()->set_center({
        static_cast<float> (GetScreenWidth() / 2),
        static_cast<float> (GetScreenHeight() / 2)
    });
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