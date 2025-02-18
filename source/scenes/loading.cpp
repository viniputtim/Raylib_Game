# include "scenes/loading.hpp"


Loading::Loading()
{

}


Loading::Loading(Core* core) : Scene(core)
{
    this->core->schedule_once([this]() {this->core->change_scene("main menu");}, 10);

    this->raylib = std::make_unique<Surf> ("raylib.png", this->colors[this->color]);
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
    std::shared_ptr<Rect> logo_rect {this->raylib->get_rect()};

    if (logo_rect->get_left() < 0 || logo_rect->get_right() > GetScreenWidth())
    {
        this->logo_movement.x *= -1;
        this->logo_speed += 75;
        ++this->color;
    }

    if (logo_rect->get_top() < 0 || logo_rect->get_bottom() > GetScreenHeight())
    {
        this->logo_movement.y *= -1;
        this->logo_speed += 75;
        ++this->color;
    }

    logo_rect->move_x(this->logo_movement.x * this->logo_speed * GetFrameTime());
    logo_rect->move_y(this->logo_movement.y * this->logo_speed * GetFrameTime());
    this->raylib->set_color(this->colors[this->color % this->colors.size()]);
}


void Loading::draw()
{
    ClearBackground(this->colors[this->color % this->colors.size()]);
    this->raylib->draw();
}