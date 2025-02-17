# include "scenes/main_menu.hpp"


MainMenu::MainMenu()
{

}


MainMenu::MainMenu(Core* core) : Scene(core)
{

}


MainMenu::~MainMenu()
{

}


void MainMenu::check_events()
{
    if (IsMouseButtonReleased(0))
    {
        this->core->change_scene("loading");
    }
}


void MainMenu::update()
{

}


void MainMenu::draw()
{
    ClearBackground(RAYWHITE);
    this->radar_chart->draw();
}